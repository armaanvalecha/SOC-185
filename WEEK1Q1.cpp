#include <iostream>
using namespace std;

//In this problem, we only need to find when are the number of U in the test case odd, because it is the only case when Alice can win 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;  // Read number of test cases

    while (T--) {
        int n;
        string s;
        cin >> n >> s;  // Read integer n (not used) and string s

        int counter = 0;
        for (char c : s) {
            if (c == 'U') {
                counter++;  // Count 'U' characters in the string
            }
        }

        if (counter % 2 == 1) {
            cout << "YES\n";  // Output "YES" if cntU is odd
        } else {
            cout << "NO\n";   // Otherwise, output "NO"
        }
    }

    return 0;
}
