/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/implement-queue-by-two-stacks
@Language: C++
@Datetime: 14-10-21 06:19
*/

#include <stack>
#include <stdexcept>

using namespace std;


class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        move();
        int tmp = stack2.top(); stack2.pop();
        return tmp;
    }

    int top() {
        // write your code here
        move();
        return stack2.top();
    }
    void move()
    {
        if(stack2.empty())
        {
           while(!stack1.empty())
           {
               stack2.push(stack1.top());
               stack1.pop();
           }
           if(stack2.empty()) throw exception();
        }
    }
};

