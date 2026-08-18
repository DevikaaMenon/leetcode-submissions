class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
      int n=nums.size();
      set<int>seen;
        int maxi=0,mini=nums[0];
      for(int x:nums){
        maxi=max(maxi,x);
        mini=min(mini,x);
        seen.insert(x);
      }  
      vector<int>ans;
      for(int i=mini;i<=maxi;i++){
        if(!seen.count(i)){
            ans.push_back(i);
        }
      }
      return ans;
    }
};