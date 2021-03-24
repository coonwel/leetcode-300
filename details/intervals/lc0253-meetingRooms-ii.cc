class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> que;
        for (auto interval : intervals) {
            if (!que.empty() && que.top() <= interval[0]) 
                que.pop();
            que.push(interval[1]);
        }
        return que.size();
    }
};
