class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int seenmin=prices[0];
        int cp=0,mp=0;
        for(int p:prices){
            int cp=p-seenmin;
            seenmin=min(seenmin,p);
            mp=max(cp,mp);
        }
        return mp;
    }
};