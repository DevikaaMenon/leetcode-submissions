class Solution {
public:
    bool isVowel(char c){
        if(c=='A' ||c=='a'|| c=='e'||c=='E'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u'){
            return true;
        }
        else return false;
    }
    string reverseVowels(string s) {
       int n=s.length();
       int i=0;
       int j=n-1;

       while(i<j){
        if(!isVowel(s[i])){
            i++;
        }else if(!isVowel(s[j])){
            j--;
        }
        else{
            swap(s[i],s[j]);
            i++;
            j--;
        }
       }
       return s; 
    }
};