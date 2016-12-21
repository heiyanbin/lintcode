/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: C++
@Datetime: 15-04-18 03:23
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        
        // max product of subarrays ending with current element
        int maxProduct = 1;
        
        // min product of subarrays ending with current element
        int minProduct = 1;
        
        int res = INT_MIN;
        
        for (int x : nums) {
            int newMaxProduct = max(x, max(maxProduct * x, minProduct * x));
            int newMinProduct = min(x, min(minProduct * x, maxProduct * x));
            maxProduct = newMaxProduct;
            minProduct = newMinProduct;
            res = max(res, maxProduct);
        }
        
        return res;
    }
};
