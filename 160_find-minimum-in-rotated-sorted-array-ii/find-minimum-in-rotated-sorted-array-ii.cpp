/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 14-12-30 04:20
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    /*
        invariant: the min is within the range [l, r]
        loop can stop: each loop the range is reduced
        loop exit condition: the range has one element, or is monotonic, and we
        have the invariant property the min is in the range, so it has to be num[l]
    */
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r && num[l] >= num[r]) {
            int mid = l + (r - l) / 2;
            if (num[mid] > num[r])
                l = mid + 1;
            else if (num[mid] < num[r])
                r = mid;
            else 
                r--;
        }
        return num[l];
    }
};
