class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int a=0,b=0;
        int l=0,r=piles.size()-1;
        while(l<r){
            if(piles[l]>piles[r]){
                a+=piles[l];
                l++;
                b+=piles[r];
                r--;
            }
            else{
                a+=piles[r];
                r--;
                b+=piles[l];
                l++;
            }
        }
        return a>b;
    }
};