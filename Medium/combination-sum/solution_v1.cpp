class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>nums,vector<int> temp,int target,int i){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,temp,target-nums[i],i);
        temp.pop_back();
        solve(nums,temp,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(candidates,temp,target,0);
        return res;
    }
};