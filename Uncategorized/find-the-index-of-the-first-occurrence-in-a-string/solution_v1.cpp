class Solution {
public:
    int strStr(string haystack, string needle) {
       int h=haystack.length();
       int n=needle.length();
       char c=needle[0];
       int i=0;
       for(i=0;i<h;i++){
        if(haystack[i]==c){
            string check=haystack.substr(i,n);
            if(check==needle) return i;
        }
       } 
       return -1;
    }
};