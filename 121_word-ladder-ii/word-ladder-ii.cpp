/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/word-ladder-ii
@Language: C++
@Datetime: 14-12-09 08:08
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        unordered_map<string,vector<string>> prev;
        queue<string> q;
        q.push(start);
        string levelEnd=start;
        unordered_set<string> levelVisited, visited;
        visited.insert(start);
        bool found = false;
        while(!q.empty())
        {
            string word = q.front(); q.pop();
            string word1 = word;
            for(char &c :word1) 
            {
                char temp = c;
                for(char l='a';l<='z';l++) {
                    if(l==temp) continue;
                    c=l;
                    if(word1==end) {
                        prev[word1].push_back(word);
                        found = true;
                        break;
                    }
                    else if(visited.find(word1)==visited.end() && dict.find(word1)!=dict.end())
                    {
                        levelVisited.insert(word1);
                        prev[word1].push_back(word);
                    }
                }
                c=temp;
            }
            if(word==levelEnd) {
                if(found) break;
                for(auto &e :levelVisited){
                    visited.insert(e);
                    q.push(e);
                }
                levelVisited.clear();
                if(!q.empty()) levelEnd = q.back();
            }
        }
        vector<vector<string>> res;
        vector<string> path;
        get_path(end,start,path,prev,res);
        return res;
    }
    void get_path(string &s, string &start, vector<string> &path, unordered_map<string,vector<string>> &prev, vector<vector<string>> &res)
    {
        path.push_back(s);
        if(s==start)
            res.push_back(vector<string>(path.rbegin(),path.rend()));
        else
            for(auto &word : prev[s])
                get_path(word,start,path,prev,res);
        path.pop_back();
    }
};
