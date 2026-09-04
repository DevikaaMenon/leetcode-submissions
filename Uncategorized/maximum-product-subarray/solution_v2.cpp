class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxprod=nums[0];
        int minprod=nums[0];
        int ans=nums[0];

        for(int i=1;i<n;i++){
            int currmin=min({
                nums[i],nums[i]*maxprod,nums[i]*minprod
            });
            int currmax=max({
                nums[i],nums[i]*maxprod,nums[i]*minprod
            });

            maxprod=currmax;
            minprod=currmin;

            ans=max(maxprod,ans);
        }
        return ans;
    }
};