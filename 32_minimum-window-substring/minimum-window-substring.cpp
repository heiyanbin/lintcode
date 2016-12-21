/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/minimum-window-substring
@Language: C++
@Datetime: 14-10-31 07:03
*/

class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here"
        vector<int> expected_count(256), appeared_count(256);
        for(char c:target)
            expected_count[c]++;
        int start=0, end=0, appeared=0, minStart=0,minLen = INT_MAX;
        for(;end<source.size();end++)
        {
            appeared_count[source[end]]++;
            if(expected_count[source[end]]>0 &&appeared_count[source[end]]<=expected_count[source[end]])
                appeared++;
            if(appeared==target.size())
            {
                while(appeared_count[source[start]]>expected_count[source[start]])
                {
                    appeared_count[source[start]]--;
                    ++start;
                }
                if(end-start+1<minLen)
                {
                    minStart=start;
                    minLen = end -start +1;
                }
            }
        }
        return minLen==INT_MAX ? "" : source.substr(minStart,minLen);
    }
};

