#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Check for each number from 0 to n
        for (int num = 0; num <= n; num++) {
            bool found = false;
            // Search through the array
            for (int i = 0; i < n; i++) {
                if (nums[i] == num) {
                    found = true;
                    break;
                }
            }
            if (!found) return num;
        }
        return -1; // Shouldn't reach here for valid inputs
    }
};