/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/recover-rotated-sorted-array
@Language: C++
@Datetime: 14-10-19 16:49
*/

#include <vector>

using namespace std;

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int i=0,j=nums.size()-1,k=-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(nums[mid]>=nums[i])
            {
                if(nums[mid]<= nums[j])
                {
                    k=mid;
                    break;
                }
                else
                    i=mid+1;
            }
            else
                j=mid;
        }
        if(k>=0) return;
        reverse(nums.begin(),nums.begin()+i);
        reverse(nums.begin()+i,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
