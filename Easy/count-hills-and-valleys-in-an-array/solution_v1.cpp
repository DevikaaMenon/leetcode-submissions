class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int v=0,h=0;
        int j,k;
        int prev=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            if(prev<nums[i] && nums[i+1]<nums[i]) h++;
            if(prev>nums[i] && nums[i+1]>nums[i]) v++;

            prev=nums[i];
        }
        return v+h;
    }
};