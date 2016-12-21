/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters
@Language: C++
@Datetime: 15-05-13 07:33
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        vector<int> lastPosition(256, -1);
        int numChars= 0, maxLen = 0;
        for (int start = 0, i = 0; i < s.size(); i++) {
            if (lastPosition[s[i]] < start) numChars++;
            lastPosition[s[i]] = i;
            while (numChars > k) {
                if (lastPosition[s[start]] == start) numChars--;
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
