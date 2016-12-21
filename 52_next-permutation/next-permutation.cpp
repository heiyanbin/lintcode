/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/next-permutation
@Language: C++
@Datetime: 14-10-22 06:47
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        // write your code here
        if(nums.size()<=1) return nums;
        int pivot = nums.size()-2;
        for(;pivot>=0 && nums[pivot]>=nums[pivot+1];pivot--);
        if(pivot<0) 
            return vector<int>(nums.rbegin(),nums.rend());
        int i=nums.size()-1;
        for(;i>=0 && nums[i]<=nums[pivot];i--);
        swap(nums[i],nums[pivot]);
        reverse(nums.begin()+pivot+1,nums.end());
        return nums;
    }
};
