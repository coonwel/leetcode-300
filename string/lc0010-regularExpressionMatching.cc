class Solution {
public:
    bool isMatch(string& s, string& p) {
        isMatch(s.c_str(), p);
    }

    bool isMatch(char* s, char* p.c_str()) {
        if (*p == '\0') return *s == '\0';

        if (*(p+1) == '*')
            if ((*p == '.' && (*s != '\0')) || *p == *s)
                return isMatch(s, p+2) || isMatch(s+1, p+2) || isMatch(s+1, p);
            else
                return isMatch(s, p+2);
        else if ((*p == '.' && (*s != '\0')) || *p == *s)
            return isMatch(s+1, p+1);
        else
            return false;
    }
};
