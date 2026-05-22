import json
import os

def main():
    print("📝 Generating a professional README table...")
    
    # 1. Load the database safely
    try:
        with open('metadata/database.json', 'r', encoding='utf-8') as f:
            data = json.load(f)
    except FileNotFoundError:
        print("❌ Error: database.json not found. Run auto_discover.py first.")
        return

    # 2. Build the professional table content using ONLY json fields
    table_content = "\n| # | Problem Title | Difficulty | Category | LeetCode | Solution |\n"
    table_content += "| :---: | :--- | :---: | :--- | :---: | :---: |\n"
    
    for prob in data.get('problems', []):
        prob_id = f"{prob['id']:04d}"
        title = prob['title']
        category = prob.get('category', 'Unknown')
        
        # 🎨 Professional Difficulty Formatting
        diff = prob.get('difficulty', 'Unknown').lower()
        if diff == "easy":
            diff_html = "🟩 Easy"
        elif diff == "medium":
            diff_html = "🟨 Medium"
        elif diff == "hard":
            diff_html = "🟥 Hard"
        else:
            diff_html = "⬜ Unknown"
            
        # 💻 Local Solution Link
        safe_title = title.lower().replace(' ', '_').replace('-', '_')
        file_name = f"{prob_id}_{safe_title}.hpp"
        local_link = f"./{category}/{file_name}"
        
        # 🔗 Auto-generate LeetCode URL based on problem title
        lc_slug = title.lower().replace(' ', '-').replace("'", "")
        lc_link = f"https://leetcode.com/problems/{lc_slug}/"
        
        # Assemble the row
        table_content += f"| **{prob_id}** | {title} | {diff_html} | `{category.capitalize()}` | [🔗 Link]({lc_link}) | [💻 Code]({local_link}) |\n"

    # 3. Read the existing README from the src folder
    readme_path = 'src/README.md'
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print(f"❌ Error: {readme_path} not found.")
        return
        
    # 4. Find the injection markers
    start_marker = ""
    end_marker = ""
    
    start_idx = -1
    end_idx = -1
    
    for i, line in enumerate(lines):
        if start_marker in line:
            start_idx = i
        elif end_marker in line:
            end_idx = i
            
    # Safety Check
    if start_idx == -1 or end_idx == -1 or start_idx >= end_idx:
        print(f"❌ Error: Markers missing or incorrectly placed in {readme_path}.")
        print(f"Ensure both '{start_marker}' and '{end_marker}' are in the file.")
        return
        
    # 5. Bulletproof Injection
    top_half = lines[:start_idx + 1]
    bottom_half = lines[end_idx:]
    
    new_readme_lines = top_half + [table_content + "\n"] + bottom_half
    
    # 6. Write it back
    with open(readme_path, 'w', encoding='utf-8') as f:
        f.writelines(new_readme_lines)
        
    print(f"✅ SUCCESS! Professional table generated in {readme_path}.")

if __name__ == "__main__":
    main()