class Solution {
public:
    bool is_operator(const string& op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (is_operator(token) == false) {
                stk.push(stoi(token));
            } else {
                int y = stk.top(); stk.pop();
                int x = stk.top(); stk.pop();

                if (token == "+") x += y;
                if (token == "-") x -= y;
                if (token == "*") x *= y;
                if (token == "/") x /= y;
                stk.push(x);
            }
        }
        return stk.top();
    }
};
