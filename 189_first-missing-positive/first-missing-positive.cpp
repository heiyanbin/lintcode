/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/first-missing-positive
@Language: C++
@Datetime: 15-04-13 08:52
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        
        for (int i = 0; i < A.size(); ++i) {
            while (A[i] > 0 && A[i] <= A.size() && A[A[i] - 1] != A[i]) {
                swap(A[i], A[A[i] - 1]);
            }
        }
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != i + 1) return i + 1;
        }
        
        return A.size() + 1;
    }
};
