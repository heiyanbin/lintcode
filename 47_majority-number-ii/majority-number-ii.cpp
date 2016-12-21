/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 15-01-24 04:13
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        int a = nums[0], countA = 1;
        int i = 1;
        for (; nums[i] == a && i<nums.size(); ++countA, ++i)
        if (i == nums.size()) return a;
        
        int b = nums[i], countB = 1;
        for ( i= i + 1; i < nums.size(); i++) {
            if(countA==0) {
                a = nums[i];
                countA = 1;
            } else if (countB == 0) {
                b = nums[i];
                countB = 1;
            }
            else {
                if (nums[i] == a) countA++;
                else if (nums[i] == b) countB++;
                else {
                    countA--;
                    countB--;
                }
            }
        }
        countA = 0, countB = 0;
        for (int &item : nums) {
            if (item == a ) countA++;
            else if (item == b) countB++;
        }
        return countA > countB ? a : b;
    }
};

