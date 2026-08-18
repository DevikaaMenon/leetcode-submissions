class Solution {
public:
    int climbStairs(int n) {
        //vector<int>dp(n+1);
        int a=1;
        int b=2,c=0;
        if(n==1) return 1;
        else if(n==2) return 2;
        else{
        
        for(int i=3;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        }
        return c;
    }
};