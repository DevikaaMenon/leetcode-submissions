class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int len=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>evens;
            unordered_set<int>odds;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0) evens.insert(nums[j]);
                else odds.insert(nums[j]);

                if(evens.size()==odds.size()){
                    len=max(len,j-i+1);
                }
            }
        }
        return len;
    }
};