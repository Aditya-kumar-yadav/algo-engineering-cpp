#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::unordered_map<int, int> counts;
    bool possible = true;
    
    // Reads input and checks frequency instantly
    while (std::cin >> n) {
        if (++counts[n] > 2) possible = false;
    }
    
    std::cout << (possible ? "true" : "false") << std::endl;
    return 0;
}