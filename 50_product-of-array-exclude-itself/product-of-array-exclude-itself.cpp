/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 14-10-21 17:06
*/

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        if(nums.size()<=1) return vector<long long>();
        vector<long long> B(nums.size(),1),C(nums.size(),1),D(nums.size(),1);
        B[0]=nums[0];
        for(int i=1;i<nums.size();++i)
            B[i]=nums[i]*B[i-1];
            
        C[nums.size()-1]=nums[nums.size()-1];    
        for(int i=nums.size()-2;i>=0;--i)
            C[i]=nums[i]*C[i+1];
            
        for(int i=1;i<nums.size()-1;i++)
            D[i]=B[i-1]*C[i+1];
            
        D[0]=C[1];
        D[nums.size()-1]=B[nums.size()-2];
        return D;
        
    }
};
