/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/expression-evaluation
@Language: C++
@Datetime: 15-06-23 11:33
*/

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
		map <char, function<int(int, int)>> m = { { '+', [](int a, int b) -> int { return a + b; } },
		{ '-', [](int a, int b) -> int { return a - b; } },
		{ '*', [](int a, int b) -> int { return a * b; } },
		{ '/', [](int a, int b) -> int { return a / b; } } };

		stack<char> op;
		stack<int> oprand;
		expression.push_back("#");
		for (int i = 0; i < expression.size(); ++i) {
			if (isdigit(expression[i][0])) oprand.push(stoi(expression[i]));
			else {
				while (!op.empty() && expression[i] != "(" && op.top() != '(' && (expression[i] == "#" || expression[i] == ")" || expression[i] == "+" || expression[i] == "-" || op.top() == '*' || op.top() == '/')) {
					int b = oprand.top(); oprand.pop();
					oprand.top() = m[op.top()](oprand.top(), b);
					op.pop();
				}
				if (expression[i] == ")") op.pop();
				else op.push(expression[i][0]);
			}
		}
		if (oprand.empty()) return 0;
		return oprand.top();
	}
};
