
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        return KMP(haystack, needle);
    }

    void compute_next(string& pattern, vector<int>& next) {
        next[0] = -1;
        for (int i = 1, j = -1; i < pattern.size(); i++) {
            while (j > -1 && pattern[i] != pattern[j+1]) {
                j = next[j];
            }
            if (pattern[i] == pattern[j+1]) j++;

            next[i] = j;
        }
    }

    int KMP(string& text, string pattern) {
        vector<int> next(pattern.size());
        compute_next(pattern, next);
    
        for (int i = 0, j = -1; i < text.size(); i++) {
            while (j > -1 && text[i] != pattern[j+1]) {
                j = next[j];
            }
            if (text[i] == pattern[j+1]) j++;

            if (j+1 == pattern.size()) return i - j;
        }
        return -1;
    }
};
