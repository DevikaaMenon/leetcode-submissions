class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minprice=prices[0],currprof=0,maxprof=0;

        for(int p:prices){
            currprof=p-minprice;
            maxprof=max(maxprof,currprof);
            minprice=min(minprice,p);
        }
        return maxprof;
    }
};