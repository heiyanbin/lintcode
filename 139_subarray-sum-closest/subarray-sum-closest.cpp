/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subarray-sum-closest
@Language: C++
@Datetime: 15-04-27 01:56
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        if (nums.empty()) return vector<int>();
        
        vector<pair<int,int>> prefixSum;
        prefixSum.push_back(make_pair(0, -1));
        for (int i = 0;i < nums.size(); ++i)
            prefixSum.push_back(make_pair(nums[i] + prefixSum.back().first, i));
            
        sort(prefixSum.begin(), prefixSum.end());
        
        int minDiff = INT_MAX, start = 0, end = 0;
        for (int i = 1; i < prefixSum.size(); i++) {
            if (abs(prefixSum[i].first - prefixSum[i-1].first)  < minDiff) {
                minDiff = abs(prefixSum[i].first - prefixSum[i-1].first);
                start = min(prefixSum[i].second, prefixSum[i-1].second) + 1; 
                end = max(prefixSum[i].second, prefixSum[i-1].second);
            }
        }
        
        return vector<int> {start, end};
    }
};

