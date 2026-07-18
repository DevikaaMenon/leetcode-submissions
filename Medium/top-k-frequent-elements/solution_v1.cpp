class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        //build hashmap
        unordered_map<int,int> hmap;
        for(int num:nums){
            hmap[num]++;
        }
        //build bucket
        vector<vector<int>>bucket(n+1);
        for(auto& [key,val]:hmap){
            bucket[val].push_back(key);
        }
        //build ans vector
        vector<int>ans;

        //return ans
        for(int i=n;i>=1;i--){
            for(int nb:bucket[i]){
                ans.push_back(nb);

                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};