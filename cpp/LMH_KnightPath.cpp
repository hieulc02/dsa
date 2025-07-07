/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//Mã đi tuần: Cho bàn cờ tổng quát kích thước nxn và một quân Mã, hãy chỉ ra một hành trình của quân Mã 
//xuất phát từ ô đang đứng đi qua tất cả các ô còn lại của bàn cờ, mỗi ô đúng 1 lần.

//Ví dụ dưới đây cho trường hợp: 8x8


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int rows[] = { -2, -2, -1,  1,  2,  2,  1, -1 };
int cols[] = { -1,  1, -2, -2, -1,  1,  2,  2 };

vector<int> moved;
vector<vector<int>> path;

bool isValid(int row, int col){
    return row >= 1 && row <= n 
        && col >= 1 && col <= n 
        && path[row][col] == 0;
}

int getDegree(int r, int c){
    int cnt = 0;
    
    for(int i = 0; i < 8; ++i){
        int nr = r + rows[i];
        int nc = c + cols[i];
        if(isValid(nr, nc))
            ++cnt;
    }
    
    return cnt;
}


void print(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

bool solve(int row, int col, int square){

    if(square == n*n + 1){
        print();
        return true;
    }
    
    vector<pair<int, int>> nextMoves;
    for(int i = 0; i < 8; ++i){
        int new_row = row + rows[i];
        int new_col = col + cols[i];
        
        if(isValid(new_row, new_col)){
            int deg = getDegree(new_row, new_col);
            nextMoves.push_back({deg, i});
        }
    }
    
    sort(nextMoves.begin(), nextMoves.end());
    
    for(auto &p : nextMoves){
        int i = p.second;
        int nr = row + rows[i];
        int nc = col + cols[i];
        
        path[nr][nc] = square;
        if(solve(nr, nc, square + 1)) 
            return true;
        path[nr][nc] = 0;
    }
    
    cout << endl;
    
    return false;
}

int main()
{
    cin >> n;
    
    path.resize(n+1, vector<int>(n+1, 0));
    moved.resize(n+1, false);
    
    path[1][1] = 1;
    moved[1] = true;
    
    if(!solve(1, 1, 2)){
      cout << "no solution found";  
    };

    return 0;
}
