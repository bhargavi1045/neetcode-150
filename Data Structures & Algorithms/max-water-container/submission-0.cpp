class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();

        int leftPointer=0;
        int rightPointer=n-1;
        int maxArea=0;
        int area;

        while(leftPointer<=rightPointer){
            area=min(heights[leftPointer],heights[rightPointer])*(rightPointer-leftPointer);
            maxArea=max(area,maxArea);

            if(heights[leftPointer]>heights[rightPointer]) rightPointer--;
            else leftPointer++;
        }

        return maxArea;
    }
};
