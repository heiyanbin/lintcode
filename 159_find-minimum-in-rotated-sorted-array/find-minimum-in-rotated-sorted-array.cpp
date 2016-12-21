/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: C++
@Datetime: 14-12-30 03:59
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
     /*
     *invariant : the min is within [l, r]
      when loop exit, either the range has only one element, either monotonic 
     */
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r && num[l] > num[r]) { 
            int mid = l + (r - l) / 2;
            if (num[mid] > num[r]) l = mid + 1;
            else r = mid;
        }
        return num[l];
    }
};
