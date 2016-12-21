/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 15-01-18 10:12
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int i = 0;
        for (int j = 0; j < A.size(); ++j) 
            if (A[j] != elem) A[i++] = A[j];
        return  i;
    }
};
