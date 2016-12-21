/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/edit-distance
@Language: C++
@Datetime: 14-11-23 17:20
*/

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        vector<int> d(word2.size()+1);
        for(int j=0;j<=word2.size();++j) d[j]=j;
        for(int i=1;i<=word1.size();++i)
        {
            d[0]=i;
            for(int j=1,leftup=i-1;j<=word2.size();++j)
            {
                int cur = word1[i-1]==word2[j-1] ? cur=leftup: min(min(leftup+1, d[j]+1), d[j-1]+1);
                leftup = d[j];
                d[j] = cur;
            }
        }
        return d[word2.size()];
    }
};

