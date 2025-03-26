class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        for(int right=0;right<nums.size();right++){
            if(nums[right]!=0){
                swap(nums[right],nums[left]);
                left++;
            }
        }
    }
};