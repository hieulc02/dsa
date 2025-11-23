#include <bits/stdc++.h>
using namespace std;


void solve(int a[], int n){
    
    vector<int> dp(n+1, 0), trace(n+1, 0);
    
  //  dp.assign(n+1, 0);
    
    dp[n+1] = 1;
    
    for(int i = n; i >= 0; i--){
        int jMax = n + 1;
        
        for(int j = i + 1; j <= n + 1; j++){
            
            if(a[j] > a[i] && dp[j] > dp[jMax]) 
                jMax = j;
            
            dp[i] = dp[jMax] + 1;
            trace[i] = jMax;
            
        }
        
    }
    
    int i = trace[0];
    
    while(i != n+1){
        cout << a[i] << " ";
        i = trace[i];
    }
    
    cout << endl;
}
    

int main() {
	// your code goes here
    int n;
    cin >> n;
    
    int a[12];
    
    a[0] = -1, a[n+1] = 100;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    solve(a, n);
        
    return 0;
}
