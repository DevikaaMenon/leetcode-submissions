class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
       
        int low=0,high=n-1,maxarea=0;
        while(low<high){
            int w=high-low;
            int h=min(height[low],height[high]);
            int a=w*h;
            maxarea=max(maxarea,a);
            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return maxarea;
    }
};