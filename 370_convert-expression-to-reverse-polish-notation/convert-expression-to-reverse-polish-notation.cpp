/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/convert-expression-to-reverse-polish-notation
@Language: C++
@Datetime: 15-05-05 09:27
*/

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
		// write your code here
		vector<string> res;
		stack<string> s;
		expression.push_back("#");
		for (string &token : expression) {
			if (isNum(token)) res.push_back(token);
			else if (token == "(") s.push(token);
			else if (token == ")") {
				while (!s.empty() && s.top() != "(") {
					res.push_back(s.top());
					s.pop();
				}
				if (!s.empty()) s.pop();
			}
			else {
				while (!s.empty() && cmp(token, s.top()) <= 0) {
					res.push_back(s.top());
					s.pop();
				}
				s.push(token);
			}
		}
		return res;
	}
private:
	int cmp(string a, string b) {
		if (a == "#") return -1;
		if (b == "(") return 1;
		if ((a == "+" || a == "-") && (b == "+" || b == "-")) return 0;
		if ((a == "+" || a == "-") && (b == "*" || b == "/")) return -1;
		if ((a == "*" || a == "/") && (b == "*" || b == "/")) return 0;
		if ((a == "*" || a == "/") && (b == "+" || b == "-")) return 1;
	}
	bool isNum(string s) {
		for (char c : s) if (!isdigit(c)) return false;
		return true;
	}
};
