/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/house-robber-ii
@Language: C++
@Datetime: 16-06-16 09:33
*/

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        if (nums.size() == 1) return nums[0];
        
        int robLastHouse = 0, notRobLastHouse = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            int newRobLastHouse = notRobLastHouse + nums[i];
            int newNotRobLastHouse = max(robLastHouse, notRobLastHouse);
            
            robLastHouse = newRobLastHouse;
            notRobLastHouse = newNotRobLastHouse;
        }
        
        int a = max(robLastHouse, notRobLastHouse);
        
        robLastHouse = 0, notRobLastHouse = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            int newRobLastHouse = notRobLastHouse + nums[i];
            int newNotRobLastHouse = max(robLastHouse, notRobLastHouse);
            
            robLastHouse = newRobLastHouse;
            notRobLastHouse = newNotRobLastHouse;
        }
        
        int b = max(robLastHouse, notRobLastHouse);
        
        return max(a, b);
    }
};