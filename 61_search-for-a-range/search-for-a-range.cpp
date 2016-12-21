/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 15-09-11 04:45
*/

#include <vector>

using namespace std;

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int l = low_bound(A, target);
        if(l == A.size() || A[l] != target) return {-1, -1};
        int r = up_bound(A, target);
        return {l, r};
    }
    int low_bound(vector<int> &A, int target)
    {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (A[m] < target) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
    int up_bound(vector<int> &A, int target)
    {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (A[m] <= target) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};
