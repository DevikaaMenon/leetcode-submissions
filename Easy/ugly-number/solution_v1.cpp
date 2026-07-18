class Solution {
public:
    bool isUgly(int n) {
       if(n<=0) return false;
       int f[]={2,3,5};

       for(int fs:f){
        while(n%fs==0){
            n/=fs;
        }
       }
       return n==1;
    }
};