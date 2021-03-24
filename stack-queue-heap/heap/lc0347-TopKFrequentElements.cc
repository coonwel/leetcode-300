class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        priority_queue<pair<int,int>> myqueue;

        for (auto num : nums) {
            ++mymap[num];
        }

        for (auto pair : mymap) {
            myqueue.push({pair.second,pair.first});
        }

        vector<int> res;
        while (k--) {
            res.push_back(myqueue.top().second);
            myqueue.pop();
        }

        return res;
    }
};