/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/surrounded-regions
@Language: C++
@Datetime: 15-12-10 03:41
*/

class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int count = 0;
        vector<bool> toEdge(1, false);
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i == board.size() || j < 0 || j == board[i].size() || board[i][j] != 'O') return;
            board[i][j] = '0' + count;
            if (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) toEdge[count] = true;
            pair<int, int> dir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto &d : dir) dfs(i + d.first, j + d.second);
        };
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') {
                    dfs(i, j);
                    ++count;
                    toEdge.push_back(false);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] != 'X') board[i][j] = toEdge[board[i][j] - '0'] ? 'O' : 'X';
    }
};