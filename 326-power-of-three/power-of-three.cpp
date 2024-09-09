class Solution {
public:
    bool isPowerOfThree(int n) {
        for (int i = 0; i < 31; i++) {
            long long pow = powl(3, i);
            if (pow == n) {
                return true;
            }
        }
        return false;
    }
};
