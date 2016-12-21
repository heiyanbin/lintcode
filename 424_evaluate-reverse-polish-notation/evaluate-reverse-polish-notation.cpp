/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/evaluate-reverse-polish-notation
@Language: C++
@Datetime: 15-06-01 08:21
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
		stack<int> s;
		map<string, function<int(int, int)>> op;
		op["+"] = [](int a, int b){ return a + b; };
		op["-"] = [](int a, int b){ return a - b; };
		op["*"] = [](int a, int b){ return a * b; };
		op["/"] = [](int a, int b){ return a / b; };
		for (auto &t : tokens) {
			if (string("+-*/").find(t) == string::npos) 
				s.push(stoi(t));
			else {
				int b = s.top(); s.pop();
				int a = s.top(); s.pop();
				s.push(op[t](a, b));
			}
		}
		return s.top();
    }
};
