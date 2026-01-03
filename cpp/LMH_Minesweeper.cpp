#include <bits/stdc++.h>
using namespace std;

int desityMap[35][35];
int mineMap[35][35];

bool foundSolution = false;

int n, m;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int countMines(int r, int c){
    
    int count = 0;
    
    for(int i = 0; i < 8; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        
        if(nr >= 1 && nr <= n && nc >= 1 && nc <= m){
            if(mineMap[nr][nc] == 1){
              count++;  
            } 
        }
        
    }
    
    return count;
}

void printSolution(){
    
    int totalMines = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mineMap[i][j] == 1) totalMines++;
        }
    }
    
    cout << totalMines << endl;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << mineMap[i][j] << (j == n ? "" : " ");
        }
        cout << endl;
    }
    
}

void solve(int index){
    if(foundSolution) return;
    
    if(index == m*n){
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(countMines(i, j) != desityMap[i][j]){
                    return;
                }
            }
        }
        
        printSolution();
        foundSolution = true;
        return;
    }
    
    
    int r = index / m + 1;
    int c = index % m + 1;
    
    for(int val = 0; val <= 1; val++){
        mineMap[r][c] = val;
        
                
        bool ok = true;
        if(r > 1 && c > 1){
            if(countMines(r - 1, c - 1) != desityMap[r - 1][c - 1]){
                ok = false;
            }
        }
        
        if(ok){
            solve(index + 1);
        }
        
        if(foundSolution) return;
        
        mineMap[r][c] = 0;
    }
}

int main() {
	// your code goes here
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= m; j++){
	        cin >> desityMap[i][j];
	    }
	}
    
    solve(0);
    
    return 0;
}
