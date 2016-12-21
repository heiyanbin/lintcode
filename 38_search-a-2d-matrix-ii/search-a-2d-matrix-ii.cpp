/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix-ii
@Language: C++
@Datetime: 14-10-31 08:20
*/

#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty()) return 0;
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]==target)
                break;
            else if(matrix[i][j]<target)
                ++i;
            else
                --j;
        }
        if(i==matrix.size()||j<0) return 0;
        int count =1;
        i++;j--;
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]==target) 
            {
                count++;
                i++;j--;
            }
            else
            {
                if(matrix[i][j]<target)
                    i++;
                else
                    j--;
            }
        }
        return count;
    }
};

