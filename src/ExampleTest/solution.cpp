#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, target;
    if (!(cin >> n)) return 0;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> target;

    unordered_map<int, int> numMap;
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            cout << numMap[complement] << " " << i << endl;
            return 0;
        }
        numMap[nums[i]] = i;
    }
    return 0;
}