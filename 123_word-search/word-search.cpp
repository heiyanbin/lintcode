/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/word-search
@Language: C++
@Datetime: 15-05-27 04:26
*/

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()) return word.empty();
        vector<vector<bool>> used(board.size(),vector<bool>(board[0].size()));
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[i].size();++j)
                if(dfs(i,j,0,board,word,used)) return true;
        return false;
    }
private:
    bool dfs(int i, int j, int t, vector<vector<char> > &board, string &word,vector<vector<bool> > &used) {
        if (t == word.size()) return true;
        if (i < 0 || i > board.size() - 1|| j < 0 || j > board[i].size() - 1|| used[i][j] || board[i][j] != word[t]) return false;
        used[i][j] = true;
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &d : directions) {
            if (dfs(i + d.first, j + d.second, t + 1, board, word, used)) return true;
        }
        used[i][j] = false;
        return false;
    }
};
