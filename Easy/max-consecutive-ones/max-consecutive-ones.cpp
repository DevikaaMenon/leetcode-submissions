class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cmax=0,mmax=0;
        int n=nums.size();

       for(int num:nums){
            if(num==1){
                cmax++;
                mmax=max(mmax,cmax);
            }
            else{
                cmax=0;
            }
       }
        return mmax;
    }
};