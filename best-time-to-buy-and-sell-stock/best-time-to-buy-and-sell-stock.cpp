class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0,cp=0,cm=prices[0];
        for(int i=1;i<prices.size();i++){
            cp=prices[i]-cm;
            mp=max(mp,cp);

            cm=min(cm,prices[i]);
        }
        return mp;
    }
};