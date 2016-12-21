/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/maximum-subarray-ii
@Language: C++
@Datetime: 15-01-25 06:46
*/

#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        assert(nums.size() >= 2);
        int max1EndWith = max(nums[0] + nums[1], nums[1]), max1 = max(nums[0], max1EndWith);
        int max2EndWith = nums[0] + nums[1], max2 = max2EndWith;
        for (int i = 2; i < nums.size(); ++i) {
            max2EndWith = max(max2EndWith + nums[i], max1 + nums[i]); //nums[i] as merged into subarray 2 or itself as subarray2
            max1EndWith = max(max1EndWith + nums[i], nums[i]);
            max1 = max(max1, max1EndWith);
            max2 = max(max2, max2EndWith);
        }
        return max2;
    }
};

