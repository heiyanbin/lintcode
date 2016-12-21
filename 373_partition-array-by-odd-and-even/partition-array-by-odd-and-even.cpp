/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 15-05-24 02:57
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        for (int i = 0, j = nums.size() - 1; i < j;) {
            while (i < j && nums[i] % 2 == 1) i++;
            while (i < j && nums[j] % 2 == 0) j--;
            if (i < j) swap(nums[i], nums[j]);
        }
    }
};
