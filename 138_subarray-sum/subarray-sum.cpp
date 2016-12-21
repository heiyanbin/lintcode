/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 14-12-10 01:59
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> res;
        if(nums.empty()) return res;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            nums[i]+=i>0 ? nums[i-1] : 0;
            auto it = m.find(nums[i]);
            if(it!=m.end()){
                res.push_back(it->second+1);
                res.push_back(i);
                return res;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};
