/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/digit-counts
@Language: C++
@Datetime: 14-12-12 10:45
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int num=0;
        for(int i=0;i<=n;++i)
            num+=count(k,i);
        return num;
    }
    int count(int k, int n){
        int num=0;
        for(;n;n /=10) 
            if((n%10)==k) num++;
        return num;
    }
};
