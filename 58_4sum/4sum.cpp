/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/4sum
@Language: C++
@Datetime: 14-10-22 04:56
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of zero.
     */
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> output;
        if(num.size()<4) return output;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-3;i++)
        {
            if(i!=0 && num[i]==num[i-1])
                continue;
            for(int j=i+1;j<num.size()-2;j++)
            {
                if(j!=i+1 && num[j]==num[j-1])
                    continue;
                int begin = j+1, end = num.size()-1;
                while(begin<end)
                {
                    int sum = num[i]+num[j]+num[begin]+num[end];
                    if(sum==target)
                    {
                        output.push_back({num[i],num[j],num[begin],num[end]});
                        begin++; end--;
                        while(begin<end && num[begin]==num[begin-1])
                            begin++;
                        while(begin<end && num[end]==num[end+1])
                            end--;
                    }
                    else if(sum < target)
                        begin++;
                    else
                        end--;
                }
            }
        }
        return output;
    }
};
