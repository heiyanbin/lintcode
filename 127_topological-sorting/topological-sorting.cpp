/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/topological-sorting
@Language: C++
@Datetime: 15-01-17 03:33
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
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        for (auto node : graph)
            if (visited.find(node) == visited.end())
                dfs(node);
        return vector<DirectedGraphNode*>(res.rbegin(),res.rend());
    }
private:
    void dfs(DirectedGraphNode* start) {
        visited.insert(start);
        for (auto link : start -> neighbors)
            if (visited.find(link) == visited.end())
                dfs(link);
        res.push_back(start);
    }
    unordered_set<DirectedGraphNode*> visited;
    vector<DirectedGraphNode*> res;
};
