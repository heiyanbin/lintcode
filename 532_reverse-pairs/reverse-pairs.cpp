/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: C++
@Datetime: 16-06-12 06:12
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        vector<int> v(A.size());
        return reversePairs(A, 0, A.size() - 1, v);
    }
    
private:
    long long reversePairs(vector<int> &A, int l, int r, vector<int> &v) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        auto a = reversePairs(A, l, m, v);
        auto b = reversePairs(A, m + 1, r, v);
        
        long long c = 0;
        for (int k = l, i = l, j = m + 1; k <= r; ++k) {
            if (i > m) v[k] = A[j++];
            else if (j > r) v[k] = A[i++];
            else if (A[i] <= A[j]) v[k] = A[i++];
            else {
                v[k] = A[j++];
                c += m - i + 1;
            }
        }
        
        for (int k = l; k <= r; ++k) {
            A[k] = v[k];
        }
        
        return a + b + c;
    }
};