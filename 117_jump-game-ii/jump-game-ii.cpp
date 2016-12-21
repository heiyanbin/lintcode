/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/jump-game-ii
@Language: C++
@Datetime: 14-11-25 01:12
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int count=0,reach=0,next =0;
        for(int i=0;i<=reach;++i)
        {
            next = max(next,i+A[i]);
            if(i==reach)
            {
                count++;
                reach = next;
            }
            if(reach>=A.size()-1) break;
        }
        return reach>=A.size()-1? count : -1 ;
    }
};
