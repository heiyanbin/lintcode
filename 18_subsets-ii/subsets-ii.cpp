/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subsets-ii
@Language: C++
@Datetime: 14-10-19 08:44
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        auto sortedS = S;
        sort(sortedS.begin(),sortedS.end());
        vector<int> x;
        DFS(x,sortedS,0);
        return result;
        
    }
    void DFS(vector<int> &x, const vector<int> &S, int start)
    {
        result.push_back(x);
        for(int i=start;i<S.size();++i)
        {
            if(i!=start && S[i]==S[i-1]) continue;
            x.push_back(S[i]);
            DFS(x,S,i+1);
            x.pop_back();
        }
    }
    vector<vector<int>> result;
};

