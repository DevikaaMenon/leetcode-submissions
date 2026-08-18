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
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};