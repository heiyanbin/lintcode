/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 14-11-17 03:51
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if(nums.size()<=1) return nums.size();
        int i = 1;
        for(int j=1;j<nums.size();++j)
        {
            if(nums[j]!=nums[i-1])
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};
