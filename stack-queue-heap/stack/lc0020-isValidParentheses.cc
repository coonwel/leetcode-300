class Solution {
public:
    // 方法1
    bool isValidParentheses(const string& s) {
        stack<char> mystack;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                mystack.push(c);
            else if (c == ')' && ')' != mystack.top() ||
                     c == ']' && ']' != mystack.top() ||
                     c == '}' && '}' != mystack.top())
                return false;
            else
                mystack.pop();
        }
        return mystack.empty();
    }

    // 方法2
    bool isValidParentheses(const string& s) {
        string left  = "([{";
        string right = ")]}";
        stack<char> mystack;
        for (auto c : s) {
            if (left.find(c) != string::npos) mystack.push(c);
            else if (right.find(c) != string::npos) return false;
            else if (mystack.empty()) return false;
            else if (mystack.top() != left[right.find(c)]) return false;
            else mystack.pop();
        }
        return mystack.empty();
    }
};
