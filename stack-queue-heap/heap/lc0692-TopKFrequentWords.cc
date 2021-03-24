class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res(k);

        unordered_map<string, int> mymap;
        for (auto word : words) {
            ++mymap[word];
        }   

        // 小顶堆
        auto cmp=[](pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };  
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > myqueue(cmp);
        for (auto one: mymap) {
            myqueue.push(one);
        }   

        for (int i = myqueue.size()-1; i >= 0; --i) {
            if (myqueue.size() <= res.size()) {
                res[i] = myqueue.top().first;
            }   
            myqueue.pop();
        }   

        return res;
    }  
};