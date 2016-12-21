/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/word-ladder
@Language: C++
@Datetime: 15-05-04 15:30
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if (start == end) return 1;
        queue<string> q;
        q.push(start);
        unordered_set<string> marked;
        int dist = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++ i) {
                string word = q.front(); q.pop();
                string next = word;
                for (int j = 0; j < word.size(); ++ j) {
                    for (char c = 'a'; c < 'z'; ++ c) {
                        if (c == word[j]) continue;
                        next[j] = c;
                        if (next == end) return dist + 1;
                        if (marked.find(next) == marked.end() && dict.find(next) != dict.end()) {
                            marked.insert(next);
                            q.push(next);
                        }
                    }
                    next[j] = word[j];
                }
            }
            dist ++;
        }
    }
};
