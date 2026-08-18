class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int n=s.length();
        int l=0,r=0;
        int maxwindow=0;
        int maxfreq=0;
        for(int r=0;r<n;r++){
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            int windowlength=r-l+1;

            if(windowlength-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
            }
            windowlength=r-l+1;
            maxwindow=max(maxwindow,windowlength);
        }
        return maxwindow;
    }
};