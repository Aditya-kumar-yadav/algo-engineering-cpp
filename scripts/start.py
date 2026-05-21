import os
import argparse

def format_filename(title):
    # Converts "Two Sum" to "two_sum"
    return title.lower().replace(" ", "_").replace("-", "_")

def main():
    parser = argparse.ArgumentParser(description="Generate LeetCode boilerplate")
    parser.add_argument("--id", required=True, type=int, help="Problem ID")
    parser.add_argument("--topic", required=True, type=str, help="Topic folder (e.g., arrays, trees)")
    parser.add_argument("--title", required=True, type=str, help="Problem Title (e.g., 'Two Sum')")
    parser.add_argument("--diff", type=str, default="Medium", choices=["Easy", "Medium", "Hard"], help="Difficulty")
    
    args = parser.parse_args()
    
    padded_id = f"{args.id:04d}"
    safe_title = format_filename(args.title)
    
    # 1. Create Directories
    src_dir = f"src/{args.topic}"
    test_dir = f"tests/{args.topic}"
    os.makedirs(src_dir, exist_ok=True)
    os.makedirs(test_dir, exist_ok=True)
    
    # 2. Generate C++ Header File
    hpp_path = f"{src_dir}/{padded_id}_{safe_title}.hpp"
    hpp_content = f"""/*
 * ID: {args.id}
 * Title: {args.title}
 * Difficulty: {args.diff}
 * Companies: 
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {{
public:
    // TODO: Write your function signature here
    int solve() {{
        return 0;
    }}
}};
"""
    with open(hpp_path, "w", encoding="utf-8") as f:
        f.write(hpp_content)

    # 3. Generate GTest File
    test_path = f"{test_dir}/{safe_title}_test.cpp"
    test_content = f"""#include <gtest/gtest.h>
#include "{args.topic}/{padded_id}_{safe_title}.hpp"

TEST({safe_title.replace('_', '').capitalize()}Test, StandardCase) {{
    Solution sol;
    // EXPECT_EQ(sol.solve(), expected_value);
}}
"""
    with open(test_path, "w", encoding="utf-8") as f:
        f.write(test_content)
        
    print(f"✅ Success! Created files for [{args.id}] {args.title}:")
    print(f"  - {hpp_path}")
    print(f"  - {test_path}")

if __name__ == "__main__":
    main()