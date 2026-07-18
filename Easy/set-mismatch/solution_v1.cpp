class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num:nums){
            m[num]+=1;
        }
         int k=-1,j=-1;
        
        for(int i=1;i<=nums.size();i++){
            if(m[i]==2) k=i;
            else if(m[i]==0) j=i;
        }
        return {k,j};

    }
};