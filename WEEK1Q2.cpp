#include <iostream>
#include <string>
using namespace std;

void solve() {
    int firstPosition, secondPosition, thirdPosition, fourthPosition;
    cin >> firstPosition >> secondPosition >> thirdPosition >> fourthPosition;
    
    string sequence;
    for (int i = 1; i <= 12; ++i) {
        if (i == firstPosition || i == secondPosition) {
            sequence += 'a';
        }
        if (i == thirdPosition || i == fourthPosition) {
            sequence += 'b';
        }
    }
    
    if (sequence == "abab" || sequence == "baba") {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int testCases;
    cin >> testCases;
    
    for (int t = 0; t < testCases; ++t) {
        solve();
    }
    
    return 0;
}
