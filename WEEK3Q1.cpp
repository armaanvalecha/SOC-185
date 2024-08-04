class Solution {
public:
    int mySqrt(int x) {
unsigned int left = 0;;
        unsigned int right = (2<<16)-1;
        unsigned int middle = (left+right)/2;
        static unsigned int temp;
        while (left < right) {
            temp = middle * middle;
            // cout << middle << "  " << temp << endl;
            if (temp > x) {
                right = middle - 1;
                middle = (left+right)/2;
            } else if (temp < x) {
                left = middle + 1;
                middle = (left + right)/2;
            } else {
                return middle;
            }
        }
        while (middle * middle < x) {
            middle += 1;
        }
        while (middle * middle > x) {
            middle --;
        }

        return middle;
    }
};