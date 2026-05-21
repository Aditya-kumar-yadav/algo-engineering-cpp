import json
import os
import re

def main():
    print("📝 Updating README.md...")
    
    try:
        with open('metadata/database.json', 'r', encoding='utf-8') as f:
            data = json.load(f)
    except FileNotFoundError:
        print("❌ Error: database.json not found. Run auto_discover.py first.")
        return

    table_content = "\n| ID | Problem Title | Difficulty | Category | Frequently Asked By |\n"
    table_content += "| :--- | :--- | :---: | :--- | :--- |\n"
    
    for prob in data['problems']:
        prob_id = f"{prob['id']:04d}"
        diff = prob.get('difficulty', 'Unknown').lower()
        emoji = "🟢" if diff == "easy" else "🟡" if diff == "medium" else "🔴" if diff == "hard" else "⚪"
        file_name = f"{prob_id}_{prob['title'].lower().replace(' ', '_')}.hpp"
        link = f"./src/{prob['category']}/{file_name}"
        companies = ", ".join([f"`{c}`" for c in prob.get('companies', [])])
        
        table_content += f"| **{prob_id}** | [{prob['title']}]({link}) | {emoji} {prob.get('difficulty', 'Unknown')} | {prob['category'].capitalize()} | {companies} |\n"

    try:
        with open('README.md', 'r', encoding='utf-8') as f:
            readme_text = f.read()
    except FileNotFoundError:
        print("❌ Error: README.md not found in the root directory.")
        return
        
    marker_start = r""
    marker_end = r""
    
    pattern = re.compile(rf"({marker_start}).*?({marker_end})", re.DOTALL)
    
    if not pattern.search(readme_text):
        print("❌ Error: Could not find the injection markers in README.md.")
        return
        
    new_readme_text = pattern.sub(rf"\1{table_content}\2", readme_text)
    
    with open('README.md', 'w', encoding='utf-8') as f:
        f.write(new_readme_text)
        
    print("✅ SUCCESS! README.md table has been updated without touching your description.")

if __name__ == "__main__":
    main()