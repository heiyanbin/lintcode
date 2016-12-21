/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 15-01-03 12:33
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        int l = 0, r = array.size() - 1;
        while (l < r - 1) {
            int mid = l + (r - l) / 2;
            if (target <= array[mid]) r = mid;
            else l = mid + 1;
        }
        if (array[l] == target) return l;
        if (array[r] == target) return r;
        return -1;
    }
};
