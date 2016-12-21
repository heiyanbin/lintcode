# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/topological-sorting
@Language: Python
@Datetime: 15-05-07 23:03
'''

# Definition for a Directed graph node
# class DirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    """
    @param graph: A list of Directed graph node
    @return: A list of integer
    """
    def topSort(self, graph):
        # write your code here
        map = {}
        def mapping(node):
            if node == None: return
            map[node] = DirectedGraphNode(node.label)
            for link in node.neighbors:
                if link not in map:
                    mapping(link)
        for vertex in graph:
            if vertex not in map:
                mapping(vertex)
        
        for k, v in map.iteritems():
            for link in k.neighbors:
                map[link].neighbors.append(v)
        
        marked, topologyOrder = set([]), []
        def dfs(node):
            marked.add(node)
            for link in node.neighbors:
                if link not in marked:
                    dfs(link)
            topologyOrder.append(node)
            
        for vertex in map.itervalues():
            if vertex not in marked:
                dfs(vertex)
        
        return topologyOrder
                    
