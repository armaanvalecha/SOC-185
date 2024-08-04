#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        int n = asteroids.size();
        
        if (n == 0) return ans; // Handle empty input case

        s.push(asteroids[0]);
        int sign = 0;

        for (int i = 1; i < n; i++) {
            if (!s.empty() && s.top() > 0)
                sign = 1;
            else
                sign = 0;

            if (asteroids[i] < 0 && sign == 1) {
                while (!s.empty() && abs(asteroids[i]) > s.top() && s.top() > 0) {
                    s.pop();
                }
                if (s.empty() || s.top() < 0) {
                    s.push(asteroids[i]);
                } else if (!s.empty() && abs(s.top()) == abs(asteroids[i])) {
                    s.pop();
                }
            } else {
                s.push(asteroids[i]);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = solution.asteroidCollision(asteroids);

    cout << "Remaining asteroids: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}
