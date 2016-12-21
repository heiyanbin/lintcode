/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/find-the-missing-number
@Language: C++
@Datetime: 15-06-23 03:32
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] < nums.size() && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums[i]) return i;
        }
        
        return nums.size();
    }
};
