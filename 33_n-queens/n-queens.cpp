/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/n-queens
@Language: C++
@Datetime: 14-10-22 10:39
*/

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
         vector<int> x(n);
         vector<vector<string>> res;
         DFS(x,0,n,res);
         return res;
    }
    void DFS(vector<int> &x, int t, int n, vector<vector<string>> &res)
    {
        if(t>=n)
        {
            vector<string> s(n,string(n,'.'));
            for(int i=0;i<n;i++)
                s[i][x[i]] ='Q';
            res.push_back(s);
        }
        else
        {
            for(int j=0;j<n;++j)
            {
                int i=0;
                for(;i<t && x[i]!=j && abs(j-x[i])!=abs(t-i);i++);
                if(i<t) continue;
                x[t]=j;
                DFS(x,t+1,n,res);
            }
        }
    }
};

