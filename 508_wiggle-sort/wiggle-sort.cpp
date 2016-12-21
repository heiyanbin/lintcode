/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/wiggle-sort
@Language: C++
@Datetime: 16-06-12 01:50
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end(), [](int a, int b)->bool {return a > b;});
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};