class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pi=0,ni=1;
        vector<int> newarray(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0 ){
                newarray[pi]=nums[i];
                pi+=2;
            }
            else{
                newarray[ni]=nums[i];
                ni+=2;
            }
        }
        return newarray;
    }
};