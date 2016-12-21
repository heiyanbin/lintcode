/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/valid-sudoku
@Language: Java
@Datetime: 15-05-06 08:04
*/

class Solution {
    /**
      * @param board: the board
        @return: wether the Sudoku is valid
      */
    public boolean isValidSudoku(char[][] board) {
        boolean[][] row = new boolean[9][9], col = new boolean[9][9];
        boolean[][][] blo = new boolean[3][3][9];
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[i].length; ++j) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                if (row[i][val - 1] == true) return false;
                if (col[j][val - 1] == true) return false;
                if (blo[i / 3][j / 3][val - 1] == true) return false;
                row[i][val - 1] = true;
                col[j][val - 1] = true;
                blo[i / 3][j / 3][val - 1] = true;
            }
        }
        return true;
    }
};
