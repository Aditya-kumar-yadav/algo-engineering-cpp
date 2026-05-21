import json
import os

def main():
    print("📝 Generating README.md...")
    
    # 1. Load the database
    try:
        with open('metadata/database.json', 'r', encoding='utf-8') as f:
            data = json.load(f)
    except FileNotFoundError:
        print("❌ Error: database.json not found. Run auto_discover.py first.")
        return

    # 2. Build the top of the README
    readme_content = "# 🚀 Enterprise LeetCode Solutions\n\n"
    readme_content += "This repository contains highly optimized, production-ready C++ solutions to LeetCode problems.\n\n"
    readme_content += "## 📊 Problem Database\n\n"
    readme_content += "| ID | Problem Title | Difficulty | Category | Frequently Asked By |\n"
    readme_content += "| :--- | :--- | :---: | :--- | :--- |\n"
    
    # 3. Build the table rows
    for prob in data['problems']:
        # Format ID to always be 4 digits (e.g., 0121)
        prob_id = f"{prob['id']:04d}"
        
        # Determine the emoji
        diff = prob.get('difficulty', 'Unknown').lower()
        emoji = "🟢" if diff == "easy" else "🟡" if diff == "medium" else "🔴" if diff == "hard" else "⚪"
        
        # Build the link directly to the C++ code
        file_name = f"{prob_id}_{prob['title'].lower().replace(' ', '_')}.hpp"
        link = f"./src/{prob['category']}/{file_name}"
        
        # Format the companies
        companies = ", ".join([f"`{c}`" for c in prob.get('companies', [])])
        
        # Construct the markdown row
        row = f"| **{prob_id}** | [{prob['title']}]({link}) | {emoji} {prob.get('difficulty', 'Unknown')} | {prob['category'].capitalize()} | {companies} |\n"
        readme_content += row

    # 4. ACTUALLY WRITE TO THE README FILE
    with open('README.md', 'w', encoding='utf-8') as f:
        f.write(readme_content)
        
    print("✅ SUCCESS! README.md has been overwritten with the latest database.")

if __name__ == "__main__":
    main()