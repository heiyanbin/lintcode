/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/sort-colors-ii
@Language: C++
@Datetime: 14-12-22 04:37
*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        for (int i = 0; i < colors.size(); ++i) {
            while ( colors[i] > 0) {
                int bucket = colors[i]-1;
                if (colors[bucket] <= 0) {
                    colors[i] = 0;
                    colors[bucket]--;
                } else {
                    colors[i] = colors[bucket];
                    colors[bucket] = -1;
                }
            }
        }
        int i = colors.size()-1;
        while (colors[i] == 0) i--;
        int index = colors.size()-1;
        for (; i >= 0; --i) {
            int cnt = -colors[i];
            while (cnt > 0) {
                colors[index--] =  i + 1;
                cnt--;
            }
        }
    }
};
