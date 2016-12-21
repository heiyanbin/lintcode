/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subsets
@Language: C++
@Datetime: 14-10-18 16:12
*/

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	vector<int> x;
    	DFS(x,nums,0);
    	return output;
    }
private:
    vector<vector<int>> output;
    void DFS(vector<int> &x, vector<int> &nums,int start)
    {
        output.push_back(x);
        for(int i=start;i<nums.size();i++)
        {
            x.push_back(nums[i]);
            DFS(x,nums,i+1);
            x.pop_back();
        }
    }
    
};
