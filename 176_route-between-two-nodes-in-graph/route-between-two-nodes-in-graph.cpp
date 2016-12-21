/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/route-between-two-nodes-in-graph
@Language: C++
@Datetime: 15-05-05 05:04
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
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        return dfs(graph, s, t);
    }
private:
    unordered_set<DirectedGraphNode*> marked;
    bool dfs(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        if (s == t) return true;
        marked.insert(s);
        for (auto link : s -> neighbors) {
            if (marked.find(link) == marked.end() && dfs(graph, link, t)) 
                return true;
        }
        return false;
    }
};


