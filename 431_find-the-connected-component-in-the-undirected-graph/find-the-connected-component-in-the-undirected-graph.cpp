/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/find-the-connected-component-in-the-undirected-graph
@Language: C++
@Datetime: 15-06-28 07:53
*/

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        unordered_map<UndirectedGraphNode*, int> id;
        int count = 0;
        
        function<void(UndirectedGraphNode*)> dfs = [&](UndirectedGraphNode* v) {
            id[v] = count;
            for (auto &w : v->neighbors) {
                if (id.find(w) == id.end()) dfs(w);
            }
        };
        
        for (auto &v : nodes) {
            if (id.find(v) == id.end()) {
                dfs(v);
                ++count;
            }
        }
        vector<vector<int>> cc(count);
        for (auto &e : id) cc[e.second].push_back(e.first->label);
        for (auto &c : cc) sort(begin(c), end(c));
        return cc;
    }
};
