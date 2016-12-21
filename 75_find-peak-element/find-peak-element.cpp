/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: C++
@Datetime: 14-11-11 03:54
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int l = 1, r = A.size()-2;
        while(l<r-1)
        {
            int mid = l + (r-l)/2;
            if(A[mid]>=A[mid-1])
                l=mid;
            else if(A[mid]>=A[mid+1])
                r=mid;
            else
                r=mid-1;
        }
        return A[l]>A[r] ? l : r;
    }
};

