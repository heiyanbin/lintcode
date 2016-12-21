/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 14-12-24 17:10
*/

#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums) {
        // write your code here
        int x = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                x = nums[i];
                count = 1;
            } else {
                if (x == nums[i]) ++count;
                else --count;
            }
        }
        return x;
    }
};

