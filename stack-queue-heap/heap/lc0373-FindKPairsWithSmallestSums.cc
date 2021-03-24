class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, 
                                        vector<int>& nums2, int k) {
        auto cmp=[](pair<int,int>& a, pair<int,int>& b){
            return a.first + a.second < b.first + b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> myqueue(cmp);

        for (int i = 0; i < std::min((int)nums1.size(), k); i++) {
            for (int j = 0; j < std::min((int)nums2.size(), k); j++) {
                if (myqueue.size() < k) {
                    myqueue.push({nums1[i], nums2[j]});
                } else if (nums1[i]+nums2[j] 
                        < myqueue.top().first + myqueue.top().second) {
                    myqueue.push({nums1[i], nums2[j]});
                    myqueue.pop();
                }
            }
        }
        vector<vector<int>> res;
        while (!myqueue.empty()) {
            res.push_back({myqueue.top().first, myqueue.top().second});
            myqueue.pop();
        }

        return res;
    }
};