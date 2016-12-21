/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/permutation-sequence
@Language: C++
@Datetime: 15-05-18 09:31
*/

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        if (n == 0) return "";
        string res;
        vector<bool> used(n);
        int fac = 1;
        for (int i = 2; i <= n; i++) 
            fac *= i;
            
        k --;
        for (int i = 0; i < n; i++) {
            int f = fac / (n - i);
            int index = k / f;
            for (int j = 0, count = 0; j < n; j++) {
                if (!used[j]) {
                    if (count == index) {
                        res.push_back(j + '1');
                        used[j] = true;
                        break;
                    }
                    count++;
                }
            }
            k %=  f;
            fac = f;
        }
        return res;
    }
};
