/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/permutations-ii
@Language: C++
@Datetime: 15-05-02 15:53
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return res;
        vector<bool> used(nums.size());
        vector<int> x(nums.size());
        sort(nums.begin(), nums.end());
        DFS (nums, used, x, 0);
        return res;
    }
    
private:
    void DFS(vector<int> &nums, vector<bool> &used, vector<int> &x, int t) {
        if (t == nums.size()) res.push_back(x);
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (!used[i] && (i == 0 || nums[i] != nums[i - 1] || used[i - 1])) {
                    x[t] = nums[i];
                    used[i] = true;
                    DFS(nums, used, x, t + 1);
                    used[i] = false;
                }
            }
        }
    }
    vector<vector<int>> res;
};
