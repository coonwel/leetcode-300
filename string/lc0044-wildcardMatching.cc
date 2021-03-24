class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p) {
        if (*p == '*') {
            while (*p == '*') p++;
            if (*p == '\0') return true;
            while (*s != '\0' && isMatch(s, p)) s++;
            return (*s != '\0');
        } else if (*p == '\0' || *s == '\0') {
            return (*p == *s);
        else if (*p == *s || *p == '?') {
            return isMatch(s+1, p+1);
        } else {
            return false;
        }
    }
};
