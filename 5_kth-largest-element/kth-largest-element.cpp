/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 15-01-04 07:56
*/

#include <stdexcept>
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> &nums) {
        if (nums.size() < k) throw invalid_argument("k bigger than array size.");
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int i = partition(nums, l, r);
            if (i == k - 1) return nums[i];
            if (i > k - 1) r = i - 1;
            else l = i + 1;
        }
    }
    
    int partition(vector<int> &nums, int l, int r) {
        int i = l;
        for (int j = l + 1; j <= r; ++j)
            if (nums[j] > nums[l]) swap(nums[++i], nums[j]);
        swap(nums[l], nums[i]);
        return i;
    }
};
