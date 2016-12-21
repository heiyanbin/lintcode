/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/first-bad-version
@Language: C++
@Datetime: 14-11-05 05:19
*/

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int l = 1, r=n;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(VersionControl::isBadVersion(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};

