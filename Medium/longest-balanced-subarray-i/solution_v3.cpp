class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int m=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set <int> odds;
            unordered_set <int> evens;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) evens.insert(nums[j]);
                else{
                    odds.insert(nums[j]);
                }
                if(odds.size()==evens.size()){
                    m=max(m,j-i+1);
                }
            }
        }
                    return m;

    }
};