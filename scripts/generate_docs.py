import json

def main():
    # 1. Load the database
    with open('metadata/database.json', 'r', encoding='utf-8') as f:
        data = json.load(f)
        
    # 2. Print the table headers to the terminal
    print("\n✅ SUCCESS! COPY AND PASTE THIS EXACT TABLE INTO YOUR README.md:\n")
    print("| ID | Problem Title | Difficulty | Category | Frequently Asked By |")
    print("| :--- | :--- | :---: | :--- | :--- |")
    
    # 3. Build and print each row
    for prob in data['problems']:
        prob_id = f"{prob['id']:04d}"
        emoji = "🟢" if prob['difficulty'].lower() == "easy" else "🟡" if prob['difficulty'].lower() == "medium" else "🔴"
        file_name = f"{prob_id}_{prob['title'].lower().replace(' ', '_')}.hpp"
        link = f"./src/{prob['category']}/{file_name}"
        companies = ", ".join([f"`{c}`" for c in prob['companies']])
        
        row = f"| **{prob_id}** | [{prob['title']}]({link}) | {emoji} {prob['difficulty']} | {prob['category'].capitalize()} | {companies} |"
        print(row)
        
    print("\n------------------------------------------------------------\n")

if __name__ == "__main__":
    main()