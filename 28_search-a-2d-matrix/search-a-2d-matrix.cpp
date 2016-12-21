/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 14-10-21 17:36
*/

#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.size()<1 || matrix[0].size()<1) return false;
        int m= matrix.size(),n=matrix[0].size();
        int begin=0,end=m*n-1;
        while(begin<=end)
        {
            int mid=(begin+end)/2;
            int i=mid/n, j= mid%n;
            if(target==matrix[i][j])return true;
            else if(target<matrix[i][j]) end=mid-1;
            else begin=mid+1;
        }
        return false;
    }
};

