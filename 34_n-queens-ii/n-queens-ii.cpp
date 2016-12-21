/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/n-queens-ii
@Language: C++
@Datetime: 14-10-22 09:53
*/

class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        vector<int> x(n);
        int count=0;
        DFS(x,0,n,count);
        return count;
    }
    void DFS(vector<int> &x,int t, int n, int &count)
    {
        if(t>=n) count++;
        else
        {
            for(int j=0;j<n;++j)
            {
                if(find(x.begin(),x.begin()+t,j)!=x.begin()+t) continue;
                if(find_if(x.begin(),x.begin()+t,[&](int &col)->bool{return abs(j-col)==abs(t-(&col-&x[0]));})!=x.begin()+t) continue;
                x[t]=j;
                DFS(x,t+1,n,count);
            }
        }
    }
};

