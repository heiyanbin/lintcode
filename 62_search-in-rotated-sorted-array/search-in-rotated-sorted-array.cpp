/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array
@Language: C++
@Datetime: 15-01-04 02:00
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        for (int l = 0, r = A.size() - 1; l <= r;) {
            int mid = l + (r - l) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] > A[l]) {
                if (target >= A[l] && target < A[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (target > A[mid] && target <= A[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
