//Cho hai số nguyên dương l, n. Hãy liệt kê các xâu nhị phân độ dài n có tính chất: bất kỳ hai xâu con dài l liên tiếp nhau đều khác nhau.

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int n, l;

vector<int> ans;
vector<int> sum;

void solve(int pos) {

	if(pos == n) {
		cout << "res: ";
		for(int t : ans) {
			cout << t << " ";
		}
		cout << endl;
		return;
	}

	for(int i = 0; i <= 1; ++i) {
		ans.push_back(i);
		
		if(pos == 0) {
		    sum[pos] = 1;
		}
		else {
			if(ans[pos-1] != ans[pos]) {
				sum[pos] = 1;
			}
			else {
				sum[pos] = sum[pos-1] + 1;
			}
		}

		if(sum[pos] > l) {
			ans.pop_back();
			continue;
		}

		solve(pos+1);
		ans.pop_back();
	}
}

int main()
{
	cin >> n >> l;

	sum.resize(n+1);
	sum[0] = 1;

	solve(0);

	return 0;
}
