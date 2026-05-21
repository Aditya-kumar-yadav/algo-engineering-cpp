#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Step 1: Assume the first word is the complete common prefix
        string prefix = strs[0];
        
        // Step 2: Check this prefix against every other word in the array
        for (int i = 1; i < strs.size(); i++) {
            
            // string.find() returns 0 ONLY if the word starts with the prefix.
            // If it doesn't start with it, we enter this while loop.
            while (strs[i].find(prefix) != 0) {
                
                // Shorten our assumed prefix by 1 character from the end
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If we chopped off all characters, they have nothing in common
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        // Step 3: Whatever is left over is the longest common prefix
        return prefix;
    }
};

// Boilerplate to test locally via terminal
int main() {
    string line;
    Solution sol;
    
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<string> strs;
        string str;
        while (ss >> str) {
            strs.push_back(str);
        }
        
        string res = sol.longestCommonPrefix(strs);
        if (res.empty()) {
            cout << "<empty>\n";
        } else {
            cout << res << "\n";
        }
    }
    return 0;
}