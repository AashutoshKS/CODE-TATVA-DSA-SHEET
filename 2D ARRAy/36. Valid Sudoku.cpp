//PROBELM :
          Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
          
          Each row must contain the digits 1-9 without repetition.
          Each column must contain the digits 1-9 without repetition.
          Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
          Note:
          
          A Sudoku board (partially filled) could be valid but is not necessarily solvable.
          Only the filled cells need to be validated according to the mentioned rules.



//APPROACH :
          for each index where board[i][j] != '.' check if the dublicate value is present in the row, col, the box, If any dublicate are present 
          then the sudoko is invalid if there are no dublicate for all index we return true;



//COMPLEXITY : 
          TIME COMPLEXITY : O(9*9*9*9*9) = O(9^5) = O(1)
          SPACE COMPLEXITY : O(1)



//CODE:
          class Solution {
          public:
              bool check_row(vector<vector<char>>& board,int r,int c) {
                  char ch = board[r][c];
                  for(int i = 0;i < 9;i++) {
                      if(board[r][i] == ch && i != c) return false;
                  }
                  return true;
              }
              bool check_col(vector<vector<char>>& board,int r,int c) {
                  char ch = board[r][c];
                  for(int i = 0;i < 9;i++) {
                      if(board[i][c] == ch && i != r) return false;
                  }
                  return true;
              }
              bool check_box(vector<vector<char>>& board,int r,int c) {
                  int j = (c/3)*3;
                  int i = (r/3)*3;
                  char ch = board[r][c];
                  for(int k = i; k < i + 3;k++) {
                      for(int k1 = j; k1 < j + 3;k1++) {
                          if(board[k][k1] == ch && k != r && k1 != c) return false;
                      }
                  }
                  return true;
              }
              bool isValidSudoku(vector<vector<char>>& board) {
                  for(int i = 0;i < 9;i++) {
                      for(int j = 0;j < 9;j++) {
                          if(board[i][j] == '.') continue;
                          if(!check_row(board,i,j) || !check_col(board,i,j) || !check_box(board,i,j)) return false;
                      }
                  }
                  return true;
              }
          };
