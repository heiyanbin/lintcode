/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: C++
@Datetime: 14-12-11 15:30
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        vector<int> bitSum(32);
        for(int x : A)
            for(int j=0;j<32;++j)
                bitSum[j] += (x>>j)&1;
        int x=0;
        for(int j=0;j<32;++j)
            x |= (bitSum[j]%3)<<j;
        return x;
    }
};
