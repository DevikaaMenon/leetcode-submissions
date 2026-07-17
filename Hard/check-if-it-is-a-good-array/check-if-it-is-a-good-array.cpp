class Solution {
     int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
       }
public:
    bool isGoodArray(vector<int>& nums) {
       int gv=nums[0];
       for(int i=1;i<nums.size();i++){
        gv=gcd(gv,nums[i]);
       } 
       return gv==1;

      
    }
};