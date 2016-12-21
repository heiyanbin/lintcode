/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/the-smallest-difference
@Language: C++
@Datetime: 15-05-12 06:24
*/

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int minDiff = INT_MAX;
        for (int i = 0, j = 0; i < A.size() && j < B.size(); ) {
            if (A[i] == B[j]) return 0;
            if (A[i] < B[j]) {
                minDiff = min(minDiff, B[j] - A[i]);
                i++;
            } else {
                minDiff = min(minDiff, A[i] - B[j]);
                j++;
            }
        }
        return minDiff;
    }
};

