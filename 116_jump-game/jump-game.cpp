/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/jump-game
@Language: C++
@Datetime: 15-04-22 14:14
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        
        //invariant: the reach variable keeps the farest place  we can reach
        for (int i = 0, reach = 0; i <= reach; ++i) {
            reach = max(reach, i + A[i]);
            if (reach >= A.size() - 1) return true;
        }
        return false;
    }
};

