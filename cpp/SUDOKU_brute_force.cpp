#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<char>>& board){
    for(size_t i = 0; i < board.size(); ++i){
        for(size_t j = 0; j < board[i].size(); ++j){
            cin >> board[i][j];
        }
    }    
}

void output(vector<vector<char>>& board){
    for(size_t i = 0; i < board.size(); ++i){
        for(size_t j = 0; j < board[i].size(); ++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
}


bool isValid(int row, int col, char c, vector<vector<char>>& board){
    for(int i = 0; i < 9; ++i){
        if(board[row][i] == c || board[i][col] == c) return false;
        
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solveBoard(int row, int col, vector<vector<char>>& board){
    if(row == 9){
        return true;
    }
    
    if(col == 9){
        return solveBoard(row + 1, 0, board);
    }
    
    if(board[row][col] != '.'){
        return solveBoard(row, col + 1, board);
    } 
    
    for(char c = '1'; c <= '9'; ++c){
        if(isValid(row, col, c, board)){
         board[row][col] = c;
         if(solveBoard(row, col + 1, board)){
            return true;
         } 
         board[row][col] = '.';   
        }
    }
    
    return false;
}

void solve(vector<vector<char>>& board) {
    if(solveBoard(0, 0, board)){
        output(board);
    }else{
        cout << "SUDOKU CANNOT SOLVE!";
    }
}

int main() {
    vector<vector<char>> board(9, vector<char>(9, '.'));
    input(board);
    solve(board);
    return 0;
}
