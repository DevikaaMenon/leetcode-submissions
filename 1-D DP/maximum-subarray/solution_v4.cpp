class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int res=nums[0],ms=nums[0];
       for(int i=1;i<nums.size();i++){
         res=max(nums[i],res+nums[i]);
         ms=max(ms,res);
       } 
       return ms;
    }
};