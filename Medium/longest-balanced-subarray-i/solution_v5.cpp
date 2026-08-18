class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int m=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int>even;
            set<int>odd;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) even.insert(nums[j]);
                else odd.insert(nums[j]);

                if(even.size()==odd.size()){
                    m=max(m,j-i+1);
                }
            }
        }
        return m;
    }
};