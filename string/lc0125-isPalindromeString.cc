class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (std::isalnum(s[left]) == false)
                ++left;
            else if (std::isalnum(s[right]) == false)
                --right;
            else if (std::tolower(s[left]) != std::tolower(s[right]))
                return false;
            else { 
                left++; right--; 
            }
        }
        return true;
    }
};
