class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool val1=true,val2=true;
        //increasing
        bool inc=true;
       for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            val1=false;
            break;
       } 
    }

    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]<nums[i+1]){
            val2=false;
            break;
        }
    }
        return val1||val2;
    }
};