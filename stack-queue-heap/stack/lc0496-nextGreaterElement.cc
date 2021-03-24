class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mystack;
        unordered_map<int,int> mymap;
        for (int i = 0; i < nums2.size(); i++) {
            while (!mystack.empty() && mystack.top() < nums2[i]) {
                mymap[mystack.top()] = nums2[i];
                mystack.pop();
            }
            mystack.push(nums2[i]);
        }

        vector<int> res(nums1.size(),0);
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = (mymap.count(nums1[i]) ? mymap[nums1[i]] : -1);
        }

        return res;
    }
};
