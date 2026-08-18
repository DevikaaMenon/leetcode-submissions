class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int l=0,n=s.length(),r=0;
        int mlen=0,curlen=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            curlen=r-l+1;
            mlen=max(curlen,mlen);
            hash[s[r]]=r;
            r++;
        }
        return mlen;
    }
};