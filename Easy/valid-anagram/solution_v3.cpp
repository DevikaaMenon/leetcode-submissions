class Solution {
public:
    bool isAnagram(string s, string t) {
        int a=s.size();
        int b=t.size();
        unordered_map <char,int> mp;
        if(a!=b) return false;
        else{
            for(int i=0;i<a;i++){
                mp[s[i]]++;
                mp[t[i]]--;
            }
            for(auto& [k,v]:mp){
                if(v!=0) return false; 
            }
        }
        return true;
    }
};