class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0){
            return false;
        }
        int temp=x;
        long long p=0;
        while(temp>0){
            p=(p*10)+(temp%10);
            temp/=10;
        }
        return (p==x);
    }
};