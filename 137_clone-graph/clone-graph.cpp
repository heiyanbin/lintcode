/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/clone-graph
@Language: C++
@Datetime: 14-12-08 07:09
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(node==NULL) return NULL;
        auto newNode = new UndirectedGraphNode(node->label);
        m[node] = newNode;
        for(auto link : node->neighbors)
                newNode->neighbors.push_back(m.find(link)==m.end() ? cloneGraph(link) : m[link]);
        return newNode;
    }
private:
    map<UndirectedGraphNode*,UndirectedGraphNode*> m;
};
