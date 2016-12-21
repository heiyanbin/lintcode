/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/longest-consecutive-sequence
@Language: C++
@Datetime: 14-12-09 14:18
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        unordered_map<int,bool> used;
        for(auto &e :num) used[e]=false;
        int maxLen =1;
        for(auto &e : used) {
            if(e.second) continue;
            int len=1;
            for(int x = e.first-1;used.find(x)!=used.end();--x){
                len++;
                used[x]=true;
            }
            for(int x = e.first+1;used.find(x)!=used.end();++x){
                len++;
                used[x]=true;
            }
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};
