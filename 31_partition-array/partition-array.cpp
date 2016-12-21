/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: C++
@Datetime: 14-10-19 08:25
*/

#include <vector>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int i=-1;
        for(int j=0;j<nums.size();++j)
            if(nums[j]<k)
                swap(nums[++i],nums[j]);
        return i+1;
    }
};
