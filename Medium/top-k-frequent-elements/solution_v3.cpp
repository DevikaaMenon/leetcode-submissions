class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int n:nums){
            freq[n]++;
        }
        priority_queue <P,vector<P>,greater<P>> pq;
        for(auto & x:freq){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();

            if(ans.size()==k) return ans;
        }
        return ans;

    }
};