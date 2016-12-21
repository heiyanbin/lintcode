/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 14-10-20 09:08
*/

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        s.push(number);
        if(minS.empty()||minS.top()>=number)
            minS.push(number);
    }

    int pop() {
        // write your code here
        int tmp = s.top();
        s.pop();
        if(tmp==minS.top())
            minS.pop();
        return tmp;
    }

    int min() {
        // write your code here
        return minS.top();
    }
private:
    stack<int> s;
    stack<int> minS;
};

