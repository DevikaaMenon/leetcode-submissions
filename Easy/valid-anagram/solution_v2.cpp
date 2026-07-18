class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        else{
        unordered_map<char,int> ans;
        for(int i=0;i<s.size();i++){
            ans[s[i]]++;
            ans[t[i]]--;
        }
        for(auto & [k,v]:ans ){
            if(v!=0) return false;

        }
        }
        return true;
    }
};