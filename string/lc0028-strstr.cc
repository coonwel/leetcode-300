

int strStr(const string& haystack, const string& needle) {
    if (needle.empty()) return 0;
    if (haystack.size() < needle.size()) return -1;

    for (int i = 0; i < haystack.size() - needle.size(); i++) {
        int j;
        for (j = 0; j < needle.size(); j++) {
            if (haystack[i+j] != needle[j]) break; // 不能直接return
        }
        if (j == needle.size()) return i; // 找到了
    }
    return -1;
}


