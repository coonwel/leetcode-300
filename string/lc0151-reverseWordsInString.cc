class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int k = 0;
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (k > 0) s[k++] = ' '; // 补齐空格

                int j = i;
                while (j < s.size() && s[j] != ' ')
                    s[k++] = s[j++]; // 搬移
                reverse(s.begin() + k - (j-i), s.begin() + k);
                i = j;
            }
        }
        s.resize(k);

        return s;
    }
};
