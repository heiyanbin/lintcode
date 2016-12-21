/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/permutation-index-ii
@Language: C++
@Datetime: 15-08-18 12:05
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        long long ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            map<int, int> count;
            set<int> unique_smaller;
            count[A[i]] = 1;
            for (int j = i + 1; j < A.size(); ++j) {
                ++count[A[j]];
                if (A[j] < A[i] ) unique_smaller.insert(A[j]);
            }
            for (int e : unique_smaller) {
                --count[e];
                ans += permutate(A.size() - i - 1, count);
                ++count[e];
            }
            
        }
        return ans + 1;
    }
private:
    long long fac(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; ++i) ans *= i;
        return ans;
    }
    
    long long permutate(int n, map<int, int> &count) {
        long long ans = fac(n);
        for (auto &e : count) {
            ans /= fac(e.second);
        }
        return ans;
    }
};
