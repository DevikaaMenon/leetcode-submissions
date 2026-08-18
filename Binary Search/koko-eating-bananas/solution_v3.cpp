class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int n=piles.size();
       int l=1,r=*max_element(piles.begin(),piles.end());
       long long tt=0;
       int res=0;
       while(l<=r){
         int mid=(l+r)/2;
         tt=0;
         for(int p:piles){
            tt+=p/mid;
            if(p%mid!=0){
                tt++;
            }
         }
            if(tt<=h){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
         
       }
       return res;
    }
};