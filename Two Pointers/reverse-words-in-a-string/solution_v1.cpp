class Solution {
public:
    string reverseWords(string s) {
      stringstream ss(s);
      string token="";
      string result="";

      while(ss >> token){
        result=token+" "+result;
      }  
      int l=result.length();
      return result.substr(0,l-1);
    }
};