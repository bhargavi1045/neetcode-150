class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        int left=0;
        int right=n-1;
        int area=0;
        int leftMax=height[left];
        int rightMax=height[right];

        while(left<right){
            if(height[left]<height[right]){
                leftMax=max(leftMax,height[left]);
                area+=leftMax-height[left];
                
                left++;
            }
            else{
                rightMax=max(rightMax,height[right]);
                area+=rightMax-height[right];
                
                right--;
            }
        }
        return area;
    }
};
