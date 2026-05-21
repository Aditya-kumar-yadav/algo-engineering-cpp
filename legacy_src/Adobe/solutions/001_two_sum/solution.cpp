#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // This map will store -> {number : index}
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            // Find what number we need to add to nums[i] to reach the target
            int complement = target - nums[i];
            
            // If the complement is already in our map, we found our pair!
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, save this number and its index into the map for future checks
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    string line;
    Solution sol;
    
    // Reads from tests.txt (Line 1: Target, Line 2: Array)
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        // First line is the target integer
        int target = stoi(line);
        
        // Second line is the array of numbers
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        
        // Run the solution
        vector<int> res = sol.twoSum(nums, target);
        
        // Format the output to match expected.txt
        if (res.size() == 2) {
            cout << "[" << res[0] << ", " << res[1] << "]\n";
        } else {
            cout << "[]\n";
        }
    }
    return 0;
}