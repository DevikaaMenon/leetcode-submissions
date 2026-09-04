class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size();
       int premax=INT_MIN;
       int suffmin=INT_MAX;

        vector<int>arr(n,0);
       for(int i=n-1;i>=0;i--){
            suffmin=min(suffmin,nums[i]);
            arr[i]=min(nums[i],suffmin);
       } 
       for(int i=0;i<n;i++){
        premax=max(nums[i],premax);
        arr[i]=premax-arr[i];

        if(arr[i]<=k){
            return i;
        }
       }
       return -1;
    }
};