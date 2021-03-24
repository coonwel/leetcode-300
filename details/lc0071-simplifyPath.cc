class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        int i = 0;
        while (i < path.size())
        {
            while (i < path.size() && path[i] == '/') i++;
            if (i == path.size()) break;
            int start = i;
            while (i < path.size() && path[i] != '/') i++;
            int end = i-1;
            string s = path.substr(start, end - start + 1);
            if (s == "..")
            {
                if (!vec.empty()) vec.pop_back();
            }
            else if (s != ".")
            {
                vec.push_back(s);
            }
        }

        if (vec.empty()) return "/";
        string res;
        for (int i = 0; i < vec.size(); i++) {
            res += "/" + vec[i];
        }
        return res;
    }
};
