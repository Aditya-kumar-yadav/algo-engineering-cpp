import os
import re
import json
import glob

def discover_problems():
    print("🔍 Scanning C++ files for metadata...")
    
    # We create a brand new, empty list every time this script runs.
    # This prevents the duplicate stacking issue.
    master_db = {"problems": []}
    
    source_files = glob.glob('src/**/*.hpp', recursive=True)
    
    for file_path in source_files:
        category = os.path.basename(os.path.dirname(file_path))
        
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
            
            id_match = re.search(r'\*\s*ID:\s*(\d+)', content)
            title_match = re.search(r'\*\s*Title:\s*(.+)', content)
            diff_match = re.search(r'\*\s*Difficulty:\s*(.+)', content)
            comp_match = re.search(r'\*\s*Companies:\s*(.+)', content)
            
            if id_match and title_match:
                companies_list = []
                if comp_match:
                    companies_list = [c.strip() for c in comp_match.group(1).split(',')]
                
                # We append to the FRESH list we made at the top of the script
                master_db["problems"].append({
                    "id": int(id_match.group(1)),
                    "title": title_match.group(1).strip(),
                    "difficulty": diff_match.group(1).strip() if diff_match else "Unknown",
                    "category": category,
                    "companies": companies_list
                })

    # Sort the problems numerically by ID
    master_db["problems"].sort(key=lambda x: x["id"])

    # Overwrite the old JSON file entirely with our fresh list
    os.makedirs('metadata', exist_ok=True)
    with open('metadata/database.json', 'w', encoding='utf-8') as f:
        json.dump(master_db, f, indent=4)
        
    print(f"✅ Auto-discovery complete! Saved {len(master_db['problems'])} unique problems to database.json.")

if __name__ == "__main__":
    discover_problems()