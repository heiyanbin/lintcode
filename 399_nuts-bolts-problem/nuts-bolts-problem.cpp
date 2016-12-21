/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/nuts-bolts-problem
@Language: C++
@Datetime: 15-06-03 11:23
*/

/**
 * class Compare {
 *     public:
 *     static int cmp(int a, int b);
 * };
 * You can use Compare::cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @return: nothing
     */
    void sortNutsAndBolts(vector<int> &nuts, vector<int> &bolts) {
		// write your code here
		auto partition = [](vector<int> &A, int l, int r, int v, int flag) {
			int i = l;
			for (int j = l, k = r; j <= k; j++) {
			    int x = flag == 0 ? Compare::cmp(v, A[j]) : Compare::cmp(A[j], v);
				if (flag == 0 && x == 1 || flag == 1 && x == -1) swap(A[i++], A[j]);
				else if (flag == 0 && x == -1 || flag == 1 && x == 1) swap(A[k--], A[j--]);
			}
			return i;
		};
		function<void(int, int, int, int)> help = [&](int a, int b, int c, int d) {
			if (a >= b) return;
			int p = partition(bolts, c, d, nuts[a], 0);
			partition(nuts, a, b, bolts[p], 1);
			help(a, p - 1, c, p - 1);
			help(p + 1, b, p + 1, d);
		};
		help(0, nuts.size() - 1, 0, nuts.size() - 1);
	}
    
    
};
