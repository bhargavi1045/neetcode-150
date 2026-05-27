class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area=0;
        int maxArea=0;
        int n=heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int pse=-1;
                int nse=i;
                int value=heights[st.top()];
                st.pop();

                if(!st.empty()) pse=st.top();

                area=value*(nse-pse-1);
                maxArea=max(maxArea,area);

            }
            st.push(i);
        }

        while(!st.empty()){
           int pse=-1;
           int nse=n;
           int value=heights[st.top()];

           st.pop();

           if(!st.empty()) pse=st.top();

           area=value*(nse-pse-1);
           maxArea=max(maxArea,area);
        }

        return maxArea;
    }
};
