import os
import argparse

def create_boilerplate():
    parser = argparse.ArgumentParser(description="Scaffold a new LeetCode C++ solution and test.")
    parser.add_argument("--id", required=True, help="Problem ID (e.g., 1)")
    parser.add_argument("--topic", required=True, help="Category folder (e.g., arrays)")
    parser.add_argument("--title", required=True, help="Problem Title (e.g., 'Two Sum')")
    parser.add_argument("--diff", required=True, choices=["Easy", "Medium", "Hard"], help="Difficulty")
    
    args = parser.parse_args()
    
    prob_id_str = f"{int(args.id):04d}"
    safe_title = args.title.lower().replace(" ", "_").replace("-", "_").replace("'", "")
    base_filename = f"{prob_id_str}_{safe_title}"
    
    src_dir = os.path.join("src", args.topic)
    test_dir = os.path.join("tests", args.topic)
    
    os.makedirs(src_dir, exist_ok=True)
    os.makedirs(test_dir, exist_ok=True)
    
    hpp_path = os.path.join(src_dir, f"{base_filename}.hpp")
    cpp_path = os.path.join(test_dir, f"{base_filename}_test.cpp")
    
    # 1. Generate Strict, Enterprise-Ready .hpp File
    hpp_content = f"""/* * ID: {args.id}
 * Title: {args.title}
 * Difficulty: {args.diff}
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {{
public:
    // Paste your LeetCode function signature here.
    // ⚠️ STRICT COMPILER REMINDERS (-Wall -Werror):
    // 1. Use std::size_t for looping through container.size()
    // 2. Ensure all code paths return a value
    
}};
"""

    # 2. Generate Google Test File with Correct Pathing
    test_suite_name = args.title.replace(" ", "").replace("-", "") + "Test"
    cpp_content = f"""#include <gtest/gtest.h>
#include "{args.topic}/{base_filename}.hpp" // Strictly pathed include

TEST({test_suite_name}, DefaultTest) {{
    Solution sol;
    
    // Add your test cases here. 
    // This dummy assertion ensures the CI pipeline passes until you write real tests.
    EXPECT_TRUE(true); 
}}
"""

    # 3. Write files safely
    if not os.path.exists(hpp_path):
        with open(hpp_path, "w", encoding="utf-8") as f:
            f.write(hpp_content)
        print(f"✅ Created solution file: {hpp_path}")
    else:
        print(f"⚠️ Warning: {hpp_path} already exists. Skipping.")

    if not os.path.exists(cpp_path):
        with open(cpp_path, "w", encoding="utf-8") as f:
            f.write(cpp_content)
        print(f"✅ Created test file: {cpp_path}")
    else:
        print(f"⚠️ Warning: {cpp_path} already exists. Skipping.")

if __name__ == "__main__":
    create_boilerplate()