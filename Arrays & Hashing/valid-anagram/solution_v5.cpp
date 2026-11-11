class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>mpp(26,0);
        for(char c:s){
            mpp[c-'a']++;
        }
        for(char c:t){
            mpp[c-'a']--;
        }
        for(int n:mpp){
            if(n!=0) return false;
        }
        return true;
    }
};