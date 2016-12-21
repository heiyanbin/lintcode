/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: C++
@Datetime: 15-06-04 00:47
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        int len = 0;
        for (auto & word : dictionary) {
            if (word.size() == len)
                res.push_back(word);
            else if (word.size() > len) {
                res.clear();
                res.push_back(word);
                len = word.size();
            }
        }
        return res;
    }
};
