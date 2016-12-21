/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: C++
@Datetime: 15-02-03 04:36
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        int maxLen = 0;
        for (int &e : L) maxLen = max(maxLen, e);
        int lo = 0, hi = maxLen, maxPiece = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == 0) break;
            int count = 0;
            for (int i = 0; i < L.size(); ++i) {
                count += L[i] / mid;
                if (count >= k) break;
            }
            if (count >= k) {
                maxPiece = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return maxPiece;
    }
};
