/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning
@Language: Java
@Datetime: 15-10-29 07:36
*/

public class Solution {
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    public List<List<String>> partition(final String s) {
		final List<List<String>> ans = new ArrayList<List<String>>();
		if (s == null || s.length() == 0) return ans;
		final int n = s.length();
		final boolean[][] isPal = new boolean[n][n];
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				isPal[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 2 || isPal[i + 1][j - 1]);
			}
		}
		class DFS {
			void dfs(int i, ArrayList<String> path) {
				if (i == n) {
					ans.add(new ArrayList<String>(path));
				} else {
					for (int j = i; j < n; ++j) {
						if (isPal[i][j]) {
							path.add(s.substring(i, j + 1));
							dfs(j + 1, path);
							path.remove(path.size() - 1);
						}
					}
				}			
			}
		}
		new DFS().dfs(0, new ArrayList<String>());
		return ans;
	}
}
