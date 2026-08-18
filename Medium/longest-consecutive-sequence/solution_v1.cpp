class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=0) return 0;
        sort(nums.begin(),nums.end());
        //int l=0;
        int cl=1,ml=1;
        for(int l=1;l<nums.size();l++){
             if(nums[l] == nums[l-1]) {
                continue;          // Ignore duplicates
            }
            if(nums[l]==nums[l-1]+1){
                cl++;
                ml=max(ml,cl);
            }
            else cl=1;
        }
        return ml;
    }
};