class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(string s:strs){
            string g=s;
            sort(g.begin(),g.end());
            mp[g].push_back(s);
        }
       vector<vector<string>>ans;
       for(auto&[k,v]:mp){
        ans.push_back(v);
       }
       return ans;
    }
};