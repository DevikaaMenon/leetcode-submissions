class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int l=nums[0];
        int r=nums.back();
        unordered_set<int>st(nums.begin(),nums.end());

        for(int i=l+1;i<r;i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};