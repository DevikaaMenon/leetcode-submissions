class Solution {
public:
    int countTriples(int n) {
        int c=0,ans=0;
       for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                int x=a*a+b*b;
                c=sqrt(x);
                if(c*c==x && c<=n) ans++;
            }
       } 
       return ans;
    }
};