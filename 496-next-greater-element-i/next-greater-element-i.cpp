#include <vector>       // For using vectors (dynamic arrays)
#include <stack>        // For using stack data structure
#include <unordered_map> // For O(1) average access time hash map
using namespace std;    // Standard namespace to avoid std:: prefix

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Initialize result vector with -1 (default value when no greater element exists)
        vector<int> res(nums1.size(), -1);

        // Monotonic stack to help find next greater elements in nums2
        stack<int> stk;

        // Hash map to store each number's next greater element (number -> next greater)
        unordered_map<int, int> next_greater;

        // Step 1: Process nums2 to find next greater elements for all numbers
        for (int num : nums2) {
            // While current number is greater than stack's top element:
            // This means current number is the next greater element for those elements
            while (!stk.empty() && stk.top() < num) {
                // Map the smaller number (stack top) to current number (its next greater)
                next_greater[stk.top()] = num;
                // Remove the smaller number from stack (we've found its next greater)
                stk.pop();
            }
            // Push current number to stack to find its next greater later
            stk.push(num);
        }

        // Step 2: Fill results for nums1 using our precomputed map
        for (int i = 0; i < nums1.size(); i++) {
            // Check if current number has a next greater element in our map
            if (next_greater.count(nums1[i])) {
                // If exists, use the mapped value
                res[i] = next_greater[nums1[i]];
            }
            // If not found in map, res[i] remains -1 (as initialized)
        }

        // Return the final result vector
        return res;
    }
};