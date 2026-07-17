class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> mheap;
       for(int i=0;i<nums.size();i++){
        mheap.push(nums[i]);
        if(mheap.size()>k){
            mheap.pop();
        }
       }
        return mheap.top();

    }
};