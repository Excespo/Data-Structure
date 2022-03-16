/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expr;
        for (int i = 0; i < tokens.size(); i++) {
            string & token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = expr.top(); expr.pop();
                int num2 = expr.top(); expr.pop();
                if (token == "+") expr.push(num2 + num1);
                if (token == "-") expr.push(num2 - num1);
                if (token == "*") expr.push(num2 * num1);
                if (token == "/") expr.push(num2 / num1);
            } else {
                expr.push(stoi(token));
            }
        }
        return expr.top();
    }
};
// @lc code=end

