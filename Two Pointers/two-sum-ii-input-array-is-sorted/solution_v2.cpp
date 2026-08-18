class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int f=0,b=numbers.size()-1;
        int n=numbers.size()/2;
        while (f<b){
            int sum=numbers[f]+numbers[b];
            if(sum<target){
                f++;
            }
            else if(sum>target){
                b--;
            }
            else if(sum==target){

             return {f+1,b+1};
        }
        }
        return {-1,-1};
    }
};