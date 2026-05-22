import json
import os

def main():
    print("📝 Generating a professional README table...")
    
    try:
        with open('metadata/database.json', 'r', encoding='utf-8') as f:
            data = json.load(f)
    except FileNotFoundError:
        print("❌ Error: database.json not found.")
        return

    table_content = "\n| # | Problem Title | Difficulty | Category | LeetCode | Solution |\n"
    table_content += "| :---: | :--- | :---: | :--- | :---: | :---: |\n"
    
    for prob in data.get('problems', []):
        prob_id = f"{prob['id']:04d}"
        title = prob['title']
        category = prob.get('category', 'Unknown')
        
        diff = prob.get('difficulty', 'Unknown').lower()
        if diff == "easy":
            diff_html = "🟩 Easy"
        elif diff == "medium":
            diff_html = "🟨 Medium"
        elif diff == "hard":
            diff_html = "🟥 Hard"
        else:
            diff_html = "⬜ Unknown"
            
        safe_title = title.lower().replace(' ', '_').replace('-', '_')
        file_name = f"{prob_id}_{safe_title}.hpp"
        local_link = f"./{category}/{file_name}"
        
        lc_slug = title.lower().replace(' ', '-').replace("'", "")
        lc_link = f"https://leetcode.com/problems/{lc_slug}/"
        
        table_content += f"| **{prob_id}** | {title} | {diff_html} | `{category.capitalize()}` | [🔗 Link]({lc_link}) | [💻 Code]({local_link}) |\n"

    readme_path = 'src/README.md'
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print(f"❌ Error: {readme_path} not found.")
        return
        
    # 🔥 CHANGED: Using plain text brackets instead of HTML comments
    start_marker = "[TABLE_START]"
    end_marker = "[TABLE_END]"
    
    start_idx = -1
    end_idx = -1
    
    for i, line in enumerate(lines):
        if start_marker in line:
            start_idx = i
        elif end_marker in line:
            end_idx = i
            
    # Safety Check with Debug Info
    if start_idx == -1 or end_idx == -1 or start_idx >= end_idx:
        print(f"❌ Error: Markers missing or incorrectly placed in {readme_path}.")
        print(f"DEBUG INFO: Found Start at line {start_idx}, Found End at line {end_idx}")
        print(f"Please ensure exactly [TABLE_START] and [TABLE_END] are in the file on separate lines.")
        return
        
    top_half = lines[:start_idx + 1]
    bottom_half = lines[end_idx:]
    
    new_readme_lines = top_half + [table_content + "\n"] + bottom_half
    
    with open(readme_path, 'w', encoding='utf-8') as f:
        f.writelines(new_readme_lines)
        
    print(f"✅ SUCCESS! Professional table generated in {readme_path}.")

if __name__ == "__main__":
    main()