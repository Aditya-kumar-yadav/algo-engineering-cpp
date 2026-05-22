import json
import os

def main():
    print("📝 Updating src/README.md safely...")
    
    # 1. Load the database
    try:
        with open('metadata/database.json', 'r', encoding='utf-8') as f:
            data = json.load(f)
    except FileNotFoundError:
        print("❌ Error: database.json not found. Run auto_discover.py first.")
        return

    # 2. Build the table content
    table_content = "\n| ID | Problem Title | Difficulty | Category | Frequently Asked By |\n"
    table_content += "| :--- | :--- | :---: | :--- | :--- |\n"
    
    for prob in data['problems']:
        prob_id = f"{prob['id']:04d}"
        diff = prob.get('difficulty', 'Unknown').lower()
        emoji = "🟢" if diff == "easy" else "🟡" if diff == "medium" else "🔴" if diff == "hard" else "⚪"
        file_name = f"{prob_id}_{prob['title'].lower().replace(' ', '_')}.hpp"
        
        # LINK CHANGE: Since README is in src/, we drop the 'src/' from the path
        link = f"./{prob['category']}/{file_name}"
        
        companies = ", ".join([f"`{c}`" for c in prob.get('companies', [])])
        
        table_content += f"| **{prob_id}** | [{prob['title']}]({link}) | {emoji} {prob.get('difficulty', 'Unknown')} | {prob['category'].capitalize()} | {companies} |\n"

    # 3. Read the existing README line-by-line from the src folder
    readme_path = 'src/README.md'
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print(f"❌ Error: {readme_path} not found.")
        return
        
    # 4. Find the exact lines where your markers live
    # FIX: Added actual marker text so the script knows where to cut
    start_marker = "<!-- TABLE_START -->"
    end_marker = "<!-- TABLE_END -->"
    
    start_idx = -1
    end_idx = -1
    
    for i, line in enumerate(lines):
        if start_marker in line:
            start_idx = i
        elif end_marker in line:
            end_idx = i
            
    # Safety Check: Did it find both markers in the right order?
    if start_idx == -1 or end_idx == -1 or start_idx >= end_idx:
        print("❌ Error: Markers missing or incorrectly placed in src/README.md.")
        print(f"Ensure both '{start_marker}' and '{end_marker}' are in the file.")
        return
        
    # 5. Bulletproof Injection: Stitch the top, the new table, and the bottom together
    top_half = lines[:start_idx + 1]
    bottom_half = lines[end_idx:]
    
    new_readme_lines = top_half + [table_content + "\n"] + bottom_half
    
    # 6. Write it back safely
    with open(readme_path, 'w', encoding='utf-8') as f:
        f.writelines(new_readme_lines)
        
    print(f"✅ SUCCESS! {readme_path} table has been updated safely.")

if __name__ == "__main__":
    main()