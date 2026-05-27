class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> result;
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first<=temperatures[i]){
                st.pop();
            }
            if(st.empty()) result.push_back(0);
            else result.push_back(abs(i-st.top().second));
            st.push({temperatures[i],i});
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
