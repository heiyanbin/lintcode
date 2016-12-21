/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/combination-sum
@Language: C++
@Datetime: 14-12-08 07:42
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<int> path;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        dfs(candidates, 0, path, target, res);
        return res;
    }
    void dfs(vector<int> &candidates, int start, vector<int> &path, int target, vector<vector<int>> &res)
    {
        if(target==0)
            res.push_back(path);
        for(int i=start;i<candidates.size() && candidates[i]<=target;++i)
        {
            path.push_back(candidates[i]);
            dfs(candidates, i, path, target-candidates[i],res);
            path.pop_back();
        }
    }
};
