/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 14-10-22 04:09
*/

class Solution {
    /**
     * @param s : A string
     * @return : A string
     */
public:
    string reverseWords(string s) {
        // write your code here
        char prev=' ';
        for(int i=0,start=0;i<s.size();prev=s[i],i++)
        {
            if(prev==' '&& s[i]!=' ') start = i;
            if(s[i]!=' '&&(i==s.size()-1 || s[i+1]==' ')) 
                reverse(s.begin()+start,s.begin()+i+1);
        }
        reverse(s.begin(),s.end());
        return string(find_if(s.begin(),s.end(),[](char c)->bool{return c!=' ';}),s.end());
    }
};
