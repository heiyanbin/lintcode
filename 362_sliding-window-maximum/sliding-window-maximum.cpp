/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sliding-window-maximum
@Language: C++
@Datetime: 15-05-31 16:35
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        if (k == 0 || nums.empty()) return res;
        deque<int> Q;
        for (int i = 0; i < nums.size(); i++) {
            while (!Q.empty() && nums[Q.back()] <= nums[i]) Q.pop_back();
            while (!Q.empty() && Q.front() <= i - k) Q.pop_front();
            Q.push_back(i);
            if (i >= k - 1) res.push_back(nums[Q.front()]);
        }
        return res;
    }
};

