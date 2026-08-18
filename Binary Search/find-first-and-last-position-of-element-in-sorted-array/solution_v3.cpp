class Solution {
public:
    int leftmost(vector<int>arr,int target,int n){
        int l=0,h=n-1;
        int lm=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==target){
                lm=mid;
                h=mid-1;
            }
            else if(target>arr[mid]){
                l=mid+1;
            }
            else h=mid-1;
        }
        return lm;
    }

    int rightmost(vector<int>arr,int target,int n){
        int l=0,h=n-1;
        int lm=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==target){
                lm=mid;
                l=mid+1;
            }
            else if(target>arr[mid]){
                l=mid+1;
            }
            else h=mid-1;
        }
        return lm;
    }    

    vector<int> searchRange(vector<int>& nums, int target) {
        int left=leftmost(nums,target,nums.size());
        int right=rightmost(nums,target,nums.size());

        return {left,right};
    }
};