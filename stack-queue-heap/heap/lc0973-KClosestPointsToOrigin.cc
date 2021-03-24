class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto distance=[](const vector<int>&a, const vector<int>& b)->bool {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };
        // 大顶堆
        priority_queue<vector<int>, vector<vector<int>>, decltype(distance)> que(distance);
        int i;
        for (i = 0; i < K; i++) {
            que.push(points[i]);
        }

        for (; i < points.size(); i++) {
            if ( !distance(que.top(), points[i]) ) {
                que.pop();
                que.push(points[i]);
            }
        }
        vector<vector<int>> res;
        while (!que.empty()) {
            res.push_back(que.top());
            que.pop();
        }

        return res;
    }
};