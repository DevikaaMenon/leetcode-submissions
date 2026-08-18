class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
      vector<int>ans=nums;
      int n=nums.size();
      ans.resize(2 * n);

      for(int i=0;i<n;i++){
        ans[n+i]=ans[i];
      }  
      return ans;
    }
};