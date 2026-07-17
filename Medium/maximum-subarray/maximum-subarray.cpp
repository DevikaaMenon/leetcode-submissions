class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            res=max(nums[i],res+nums[i]);
            maxi=max(maxi,res);
        }
        return maxi;
    }
};