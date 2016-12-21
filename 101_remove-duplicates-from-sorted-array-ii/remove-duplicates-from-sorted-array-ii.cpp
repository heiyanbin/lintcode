/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii
@Language: C++
@Datetime: 14-11-17 04:07
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size()<=2) return nums.size();
        int i=2;
        for(int j=2;j<nums.size();++j)
            if(nums[j]!=nums[i-1]||nums[i-1]!=nums[i-2])
                nums[i++]= nums[j];
        return i;
    }
};
