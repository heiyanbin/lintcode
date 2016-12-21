/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-colors
@Language: C++
@Datetime: 15-05-29 17:01
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        for (int i = -1, j = -1, k = -1, p = 0; p < nums.size(); ++p) {
            if (nums[p] == 0) {
                swap(nums[j + 1], nums[++k]);
                swap(nums[++i], nums[++j]);
            }
            else if (nums[p] == 1) 
                swap(nums[++j], nums[++k]);
            else 
                k++;
        }
    }
};
