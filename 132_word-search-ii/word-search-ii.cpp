/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/word-search-ii
@Language: C++
@Datetime: 15-05-27 04:18
*/

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> res;
        for(auto &word : words)
            if(exist(board,word))
                res.push_back(word);
        return res;
    }
private:
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        if(board.empty()) return word.empty();
        vector<vector<bool>> used(board.size(),vector<bool>(board[0].size()));
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[i].size();++j)
                if(dfs(i,j,0,board,word,used)) return true;
        return false;
    }

    bool dfs(int i, int j, int t, vector<vector<char> > &board, string &word,vector<vector<bool> > &used)
    {
        if(t==word.size()) return true;
        if(i<0||i>board.size()-1||j<0||j>board[i].size()-1||used[i][j]||board[i][j]!=word[t]) return false;
        used[i][j]=true;
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool ret = false;
        for (auto &d : directions) {
            if (dfs(i + d.first, j + d.second, t + 1, board, word, used)) {
                ret = true;
                break;
            }
        }
        used[i][j]=false;
        return ret;
    }
};
