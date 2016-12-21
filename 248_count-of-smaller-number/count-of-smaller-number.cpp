/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/count-of-smaller-number
@Language: C++
@Datetime: 15-08-20 07:47
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        sort(A.begin(), A.end());
        vector<int> res;
        for (int q : queries) res.push_back(lower_bound(A.begin(), A.end(), q) - A.begin());
        return res;
    }
};
