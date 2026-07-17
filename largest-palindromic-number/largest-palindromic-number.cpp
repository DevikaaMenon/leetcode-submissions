class Solution {
public:
    string largestPalindromic(string num) {
        int freq[10]={0};
        for(int i=0;i<num.length();i++){
            int n=num[i]-'0';
            freq[n]++;
        }
        string left="";
        for(int i=9;i>=0;i--){
            int pairs=freq[i]/2;

            if (i==0 && left.empty()){
                continue;
            }
            left.append(pairs,char('0'+i));
            freq[i]-=2*pairs;

        }

        string middle="";
        for(int i=9;i>=0;i--){
            if(freq[i]>0){
                middle=char('0'+i);
                break;
            }
        }
        string right=left;
        reverse(right.begin(),right.end());

        string ans=left+middle+right;

        if(ans.empty()){
            return "0";
        }
        return ans;
    }
};