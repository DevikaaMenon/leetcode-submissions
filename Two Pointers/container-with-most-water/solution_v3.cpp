class Solution {
public:
    int maxArea(vector<int>& height) {
        int ca=0;
        int ma=0;

        int n=height.size();
        int l=0;
        int r=n-1;
        while(l<r){
            ca=0;
            int w=r-l;
            int h=min(height[l],height[r]);
            ca=w*h;
            ma=max(ca,ma);

            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ma;
    }
};