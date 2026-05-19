#include <iostream>
using namespace std;

int main() {
    int n;
    // This will read from tests.txt because we used < tests.txt in your ci.yml
    if (cin >> n) {
        cout << "Successfully read: " << n << endl;
    } else {
        cout << "No input found, but code compiled!" << endl;
    }
    return 0;
}