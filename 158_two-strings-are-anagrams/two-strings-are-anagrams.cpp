/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 15-01-06 09:19
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> c1(256), c2(256);
        for (char c : s) c1[c]++;
        for (char c : t) c2[c]++;
        for (int i = 0; i < 256; ++i) {
            if (c1[i] != c2[i]) return false;
        }
        return true;
    }
};
