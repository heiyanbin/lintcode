/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sliding-window-median
@Language: C++
@Datetime: 15-05-19 13:53
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        multiset<int> minQ, maxQ;
        for (int i = 0; i < k; i++)
            addAndAdjust(maxQ, minQ, nums[i]);
        
        for (int i = k; i < nums.size(); i++) {
            res.push_back(getMedian(maxQ, minQ));
            
            auto it = maxQ.find(nums[i - k]);
            if (it != maxQ.end()) maxQ.erase(it);
            else minQ.erase(minQ.find(nums[i - k]));
            adjust(maxQ, minQ);
            
            addAndAdjust(maxQ, minQ, nums[i]);
        }
        res.push_back(getMedian(maxQ, minQ));
        return res;
    }
private:
    void addAndAdjust(multiset<int> &maxQ, multiset<int> &minQ, int x) {
        if (!maxQ.empty() && x < *maxQ.rbegin()) maxQ.insert(x);
        else minQ.insert(x);
        adjust(maxQ, minQ);
    }
    void adjust (multiset<int> &maxQ, multiset<int> &minQ) {
        while ((int)maxQ.size() - (int)minQ.size() > 1) {
            auto it = prev(maxQ.end());
            minQ.insert(*it);
            maxQ.erase(it);
        }
        while ((int)minQ.size() - (int)maxQ.size() > 1) {
            auto it = minQ.begin();
            maxQ.insert(*it);
            minQ.erase(it);
        }
    }
    int getMedian(multiset<int> &maxQ, multiset<int> &minQ) {
        if (maxQ.size() >= minQ.size()) return *maxQ.rbegin();
        else  return *minQ.begin();
    }
};