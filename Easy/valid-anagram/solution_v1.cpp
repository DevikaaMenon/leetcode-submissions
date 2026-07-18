class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        else{
            int count[26]={0};
            for(int i=0;i<s.size();i++){
                count[s[i]-'a']++;
                count[t[i]-'a']--;
            }
            for(int it:count){
                if(it!=0) return false;
            }
        }
        return true;
    }
};