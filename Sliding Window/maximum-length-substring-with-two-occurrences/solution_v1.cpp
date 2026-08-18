class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        vector<int> hash(26,0);
        int l=0;
        int ml=0;
        for(int r=0;r<n;r++){
           hash[s[r]-'a']++;
           while(hash[s[r]-'a']>2){
            hash[s[l]-'a']--;
            l++;
           }
           ml=max(ml,r-l+1);
        }
        return ml;
    }
};