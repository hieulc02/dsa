#include <bits/stdc++.h>

using namespace std;

struct SudokuSolver{
  bool colCheck[9][10] = {false};
  bool rowCheck[9][10] = {false};
  bool boxCheck[3][3][10] = {false};
  
  void cache(int row, int col, char c, bool value){
      int v = c - '0';
      colCheck[col][v] = value;
      rowCheck[row][v] = value;
      boxCheck[row/3][col/3][v] = value;
  }
  
  bool isValid(int row, int col, char c){
          int v = c - '0';
          return !(rowCheck[row][v] || colCheck[col][v] || boxCheck[row/3][col/3][v]);
      }
      
  int searchBestCell(const vector<vector<char>>& board, int& bestR, int &bestC){
      int minCandidate = 10;
      bool emptyCell = false;
      for(int i = 0; i < 9; ++i){
          for(int j = 0; j < 9; ++j){
              if(board[i][j] == '.'){
                  emptyCell = true;
                  
                  int count = 0;
                  for(char ch = '1'; ch <= '9'; ++ch){
                      if(isValid(i, j, ch)) count++;
                  }

                  if(count == 0) return -1;

                  if(count < minCandidate){
                      minCandidate = count;
                      bestR = i;
                      bestC = j;
                  }
              }
          }
      }

      return emptyCell ? 0 : 1;
  }

  bool backtrack(vector<vector<char>>& board){
      int r = -1, c = -1;
      int result = searchBestCell(board, r, c);
      if(result == 1) return true;
      if(result == -1) return false;

      for(char ch = '1'; ch <= '9'; ++ch){
          if(isValid(r, c, ch)){
              board[r][c] = ch;
              cache(r, c, ch, true);
          
              if(backtrack(board)) return true;  
          
              board[r][c] = '.';   
              cache(r, c, ch, false);
          }
      }
      return false;
  }
  
  void solve(vector<vector<char>>& board) {
      for(int i = 0; i < 9; ++i){
          for(int j = 0; j < 9; ++j){
              if(board[i][j] != '.'){
                  cache(i, j, board[i][j], true);
              }
          }
      }
      backtrack(board);
  }     
};


void input(vector<vector<char>>& board){
    for(size_t i = 0; i < board.size(); ++i){
        for(size_t j = 0; j < board[i].size(); ++j){

            cin >> board[i][j];
        }
    }    
}


void output(vector<vector<char>>& board){
    cout << "[";
    for(size_t i = 0; i < board.size(); ++i){
        cout << "[";
        for(size_t j = 0; j < board[i].size(); ++j){
            cout << board[i][j];
            if(j != board[i].size() - 1){
                cout << ",";
            }
        }
        cout << "]";
    }
    cout << "]";
}


int main() {
    
    vector<vector<char>> board(9, vector<char>(9, '.'));
    input(board);
    SudokuSolver solver;
    solver.solve(board);
    output(board);
    return 0;

}
