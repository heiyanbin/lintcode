/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/find-the-weak-connected-component-in-the-directed-graph
@Language: C++
@Datetime: 15-08-18 10:51
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        for (auto v : nodes) {
            for (auto w : v->neighbors) {
                if (find(w->neighbors.begin(), w->neighbors.end(), v) == w->neighbors.end()) {
                    w->neighbors.push_back(v);
                }
            }
        }
        
        unordered_map<DirectedGraphNode*, int> id;
        int count = 0;
        function<void(DirectedGraphNode*)> dfs = [&](DirectedGraphNode *v) -> void {
            id[v] = count;
            for (auto w : v->neighbors) {
                if (id.find(w) == id.end()) dfs(w);
            }
        };
        
        for (auto v : nodes) {
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
