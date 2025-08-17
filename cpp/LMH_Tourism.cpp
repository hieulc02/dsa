/******************************************************************************

Cho n thành phố đánh số từ 1 đến n và m tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi bảng C cấp n×n, ở đây C[i, j] = C[j, i] = Chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j. Giả thiết rằng C[i, i] = 0 với ∀i, C[i, j] = +∞ nếu không có đường trực tiếp từ thành phố i đến thành phố j.

Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra cho người đó hành trình với chi phí ít nhất.

Bài toán đó gọi là bài toán người du lịch hay bài toán hành trình của một thương gia (Traveling Salesman Problem - TSP).

*******************************************************************************/

#include <iostream>
#include <vector>
#define MAX_C 1e9 + 7

using namespace std;

int n, m;

int a, b, k;

int bestCost;

vector<vector<int>> path;

vector<bool> visited;
vector<int> best, curr;
vector<int> cost;

void print() {
	for(int i = 1; i <= n; ++i) {
		cout << best[i] << " -> ";
	}
    
    cout << "1" << endl;
    
	//cout << "Best cost: " << bestCost;
}

void update_best_cost() {

	for(int i = 1; i <= n; ++i) {
		best[i] = curr[i];
		cout << curr[i] << " ";
	}
	cout << endl;
}

void solve(int node) {

	for(int i = 2; i <= n; ++i) {
		if(!visited[i]) {

			curr[node] = i;
			cost[node] = cost[node - 1] + path[curr[node-1]][i];

			if(cost[node] < bestCost) { 
				if(node < n) {
					visited[i] = true;
					solve(node + 1);
					visited[i] = false;
				}
				else {
				    // cout << "current bestCost: " << bestCost <<endl;
				  //  cout << "cost node: " << cost[node] << endl;
			    //   cout << "current cost: " << cost[n] <<endl;
			  //    cout << "cost to path: " << path[curr[node]][1] << endl; 
			        
					if(cost[n] + path[curr[node]][1] < bestCost) {
					    bestCost = cost[n] + path[curr[node]][1];
						update_best_cost();
					}
				}
			}
		}
	}
}

void input() {

	cin >> n >> m;

	path.assign(n+1, vector<int>(n+1, MAX_C));
	best.resize(n+1);
    curr.resize(n+1);
    cost.resize(n+1);

	visited.assign(n+1, false);

	for(int i = 0; i < m; ++i) {
		cin >> a >> b >> k;

		path[a][b] = k;
		path[b][a] = path[a][b];
	}

	for(int i = 1; i <= n; ++i) {
		path[i][i] = 0;
	}

	curr[1] = 1;
	visited[1] = true;
	cost[1] = 0;

	bestCost = MAX_C;
}


int main()
{
	input();
	solve(2);
	print();

	return 0;
}
