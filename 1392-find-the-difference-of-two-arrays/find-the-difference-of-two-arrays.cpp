#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Get sizes of both input arrays
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Create two hash sets to store unique elements from each array
        unordered_set<int> s1;  // Will store unique elements from nums1
        unordered_set<int> s2;  // Will store unique elements from nums2
        
        // Step 1: Populate s1 with elements from nums1
        // This automatically handles duplicates since sets only store unique values
        for(int i = 0; i < n1; i++) {
            s1.insert(nums1[i]);
        }
        
        // Step 2: Populate s2 with elements from nums2
        // Again, duplicates are automatically handled
        for(int i = 0; i < n2; i++) {
            s2.insert(nums2[i]);
        }
        
        // Vectors to store our final results
        vector<int> res1;  // Will contain elements only in nums1
        vector<int> res2;  // Will contain elements only in nums2
        
        // Step 3: Find elements present in s1 but not in s2
        // We iterate through all unique elements in nums1 (stored in s1)
        for(auto x : s1) {
            // Check if current element doesn't exist in s2
            if(s2.count(x) == 0) {
                res1.push_back(x);  // Add to result if unique to nums1
            }
        }
        
        // Step 4: Find elements present in s2 but not in s1
        // We iterate through all unique elements in nums2 (stored in s2)
        for(auto x : s2) {
            // Check if current element doesn't exist in s1
            if(s1.count(x) == 0) {
                res2.push_back(x);  // Add to result if unique to nums2
            }
        }
        
        // Return the two result vectors packaged together
        return {res1, res2};
    }
};