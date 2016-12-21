/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/copy-books
@Language: C++
@Datetime: 15-08-03 10:42
*/

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
    	if (k > n) k = n;
    	
    	auto guessValid = [&](int v) -> bool {
    	    int groupNum = 1, curGroupPages = 0;
    	    for (int x : pages) {
    	        if (x > v) return false;
    	        if (curGroupPages + x <= v) {
    	            curGroupPages += x;
    	        } else {
    	            ++groupNum;
    	            curGroupPages = x;
    	        }
    	    }
    	    if (groupNum <= k ) return true;
    	    return false;
    	};
    	
    	int l = 0, r = 0;
    	for (int x : pages) {
    	    l = max(l, x);
    	    r += x;
    	}
    	int ans = 0;
    	while (l <= r) {
    	    int m = l + (r - l) / 2;
    	    if (guessValid(m)) {
    	        ans = m;
    	        r = m - 1;
    	    } else {
    	        l = m + 1;
    	    }
    	}
    	return ans;
    }
};
