/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/permutation-index
@Language: C++
@Datetime: 15-08-12 16:11
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            map<int, int> c;
            set<int> s;
            for (int j = i + 1; j < A.size(); ++j) {
                c[A[j]]++;
                if (A[j] < A[i]) {
                    s.insert(A[j]);
                }
            }
            ++c[A[i]];
            for (auto x : s) {
                --c[x];
                ans += permutate(c);
                ++c[x];
                
            }
        }
        return ans + 1;
    }
private:
    long long fac(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans *= i;
        }
        return ans;
    }
    long long permutate(map<int, int> &c) {
        long long div = 1;
        int n = 0;
        for (auto &e : c) {
            if (e.second == 0) continue;
            div *= fac(e.second);
            ++n;
        }
        return fac(n) / div;
    }
};
