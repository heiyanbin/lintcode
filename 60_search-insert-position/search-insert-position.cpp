/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 14-10-19 08:51
*/

#include <vector>

using namespace std;

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int i=0,j=A.size()-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(A[mid]<target)
                i=mid+1;
            else if(A[mid]==target)
                return mid;
            else
                j=mid-1;
        }
        return i;
    }
};
