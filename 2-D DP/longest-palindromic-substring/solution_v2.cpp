class Solution {
public:
    bool checkpal(string &c,int i,int j){
        while(i<=j){
            if(c[i]==c[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkpal(s,i,j)){
                    if(j-i+1 >ans.length()){
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};