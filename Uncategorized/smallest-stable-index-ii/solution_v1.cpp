class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n,0);
        int currmin=INT_MAX,currmax=INT_MIN;
        for(int i=n-1;i>=0;i--){
            currmin=min(currmin,nums[i]);
            res[i]=currmin;
        }
        for(int i=0;i<n;i++){
            currmax=max(currmax,nums[i]);
            res[i]=currmax-res[i];

            if(res[i]<=k){
                return i;
            }
        }
        return -1;
    }
};