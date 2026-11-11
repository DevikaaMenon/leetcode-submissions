class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string prefix=strs[0];

       for(int i=1;i<strs.size();i++){
            int l=0;
            string check=strs[i];
            for(int i=0;i<check.length();i++){
                if(prefix[i]!=check[i]){
                    break;
                }
                l++;

            }
            prefix=prefix.substr(0,l);
       } 
       return prefix;
    }
};