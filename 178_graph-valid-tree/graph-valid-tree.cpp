/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/graph-valid-tree
@Language: C++
@Datetime: 15-12-14 02:49
*/

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (n == 0) return true;
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> marked(n, false);
        int vertexCount = 0;
        function<void(int)> dfs = [&](int v)->void {
            marked[v] = true, ++vertexCount;
            for (int w : adj[v]) {
                if (!marked[w]) {
                    dfs(w);
                }
            }
        };
        dfs(0);
        return vertexCount == n;
    }
};