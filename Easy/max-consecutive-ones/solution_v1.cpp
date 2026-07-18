class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flag=0,maxf=0;
        for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            flag++;
            maxf=max(flag,maxf);
        }
        else{
            flag=0;
        }
        }
            return maxf;

    }
};