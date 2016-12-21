/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 15-01-04 02:08
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        for (int l = 0, r = A.size() - 1; l <= r;) {
            int mid = l + (r - l) / 2;
            if (A[mid] == target) return true;
            if (A[mid] == A[l]) l++;
            else if (A[mid] > A[l]) {
                if (target >= A[l] && target < A[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else {
                if (target > A[mid] && target <= A[r]) l = mid + 1;
                else r = mid -1;
            }
        }
        return false;
        
    }
};
