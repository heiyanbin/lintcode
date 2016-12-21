/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/median
@Language: C++
@Datetime: 14-12-08 03:37
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        return median(nums,0,n-1,(n&1)? n/2+1 :n/2);
        
    }
    int median(vector<int> &nums, int L, int R, int k)
    {
        if(L==R) return nums[L];
        int i=L;
        for(int j=L+1;j<=R;++j)
            if(nums[j]<nums[L])
                swap(nums[++i],nums[j]);
        swap(nums[L],nums[i]);
        if(i-L+1==k) return nums[i];
        else if(i-L+1>k) return median(nums,L,i-1,k);
        else return median(nums,i+1,R,k-(i-L+1));
    }
};

