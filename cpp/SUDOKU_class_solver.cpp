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
    
    bool isValid(int row, int col, char c, vector<vector<char>>& board){
        int v = c - '0';
        return !(rowCheck[row][v] || colCheck[col][v] || boxCheck[row/3][col/3][v]);
    }
    
    
    bool backtrack(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; ++c){
                        if(isValid(i, j, c, board)){
                        board[i][j] = c;
                        cache(i, j, c, true);
                        
                        if(backtrack(board)) return true;  
                        
                        board[i][j] = '.';   
                        cache(i, j, c, false);
                        }
                    }
                    return false;
                }
            }
        }
        return true;
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
