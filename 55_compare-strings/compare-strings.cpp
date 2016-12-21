/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 14-10-21 05:01
*/

#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        vector<int> s(256,false);
        for(auto &c : A)
            s[c]++;
        for(auto &c : B)
            if(!s[c]) return false;
            else
                s[c]--;
        return true;
    }
};

