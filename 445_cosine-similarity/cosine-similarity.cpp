/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: C++
@Datetime: 15-12-14 06:53
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        if (A.empty() || B.empty() || A.size() != B.size()) return 2;
        long long a = 0, b = 0, c = 0;
        for (int i = 0; i < A.size(); ++i) {
            a += A[i] * B[i];
            b += A[i] * A[i];
            c += B[i] * B[i];
        }
        if (b == 0 && c == 0) return 2;
        return a / (sqrt(b) * sqrt(c));
    }
};
