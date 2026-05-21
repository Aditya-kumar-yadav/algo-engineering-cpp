#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        // Since constraints say 1 <= nums[i] <= 100, a simple frequency array of size 101 works perfectly
        int counts[101] = {0};
        
        // Count how many times each number appears
        for (int num : nums) {
            counts[num]++;
            
            // If any number appears more than twice, we can't split it into two distinct arrays
            if (counts[num] > 2) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    string line;
    Solution sol;
    
    // Reads each line from tests.txt as a separate test case
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        
        // Output true/false as text strings to match expected.txt easily
        if (sol.isPossibleToSplit(nums)) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
    return 0;
}