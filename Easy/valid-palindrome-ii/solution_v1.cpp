class Solution {
public:
    bool ispali(string c,int l,int r){
        while(l<r){
            if(c[l]!=c[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]!=s[r]){
                return ispali(s,l+1,r) || ispali(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};