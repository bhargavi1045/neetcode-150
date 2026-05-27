class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<points.size();i++){
            int y=points[i][1];
            int x=points[i][0];
            pq.push({x*x+y*y,i});

            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            auto point=pq.top();
            pq.pop();

            int index=point.second;
            res.push_back(points[index]);
        }
        return res;
    }
};
