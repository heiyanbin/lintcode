/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-letters-by-case
@Language: C++
@Datetime: 14-10-19 09:14
*/

#include <string>

using namespace std;

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        for(int i=-1,j=0;j<letters.size();++j)
            if(letters[j]<='z'&& letters[j]>='a')
                swap(letters[++i],letters[j]);
    }
};

