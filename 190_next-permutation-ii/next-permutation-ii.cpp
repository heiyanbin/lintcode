/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/next-permutation-ii
@Language: C++
@Datetime: 15-05-24 15:29
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) i--;
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i - 1]) j--;
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};
