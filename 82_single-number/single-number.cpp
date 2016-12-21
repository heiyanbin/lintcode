/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/single-number
@Language: C++
@Datetime: 14-10-21 11:48
*/

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int res = 0;
        for(int i=0;i<A.size();++i)
            res ^=A[i];
        return res;

    }
};

