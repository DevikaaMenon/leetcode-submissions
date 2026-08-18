class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int n=r-l+1;
        unordered_set<int>st(nums.begin(),nums.end());

        for(int i=l+1;i<r;i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};