class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       //build a frequency map
       unordered_map<int,int>freq;
       for(int n:nums){
        freq[n]++;
       } 
       vector<vector<int>>bucket(nums.size()+1);
       for(auto& [key,v]:freq){
        bucket[v].push_back(key);
       }
       vector<int>ans;

       for(int i=nums.size();i>=1;i--){
         for(int j:bucket[i]){
            ans.push_back(j);

            if(ans.size()==k){
                return ans;
            }
         }
       }
       return ans;
    } 
};