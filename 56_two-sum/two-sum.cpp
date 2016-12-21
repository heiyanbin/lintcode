/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 14-10-19 09:32
*/

#include <vector>

using namespace std;


class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        map<int,int> m;
        for(int i=0;i<nums.size();++i)
        {
            if(m.find(target-nums[i])!=m.end())
                return vector<int>{m[target-nums[i]]+1,i+1};
            else
                m[nums[i]]=i;
        }
        return vector<int>();
    }
};

