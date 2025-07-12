//Liệt kê tất cả các tập hợp con của tập S gồm n số nguyên {S[1], S[2], ..., S[n]} nhập vào từ bàn phím

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int n, k;

vector<int> v;
vector<int> out;

void print() {
	cout << "{ ";
	for(int i : out) {
		cout << i << " ";
	}
	cout << "}";
	cout << endl;
}

void solve(int pos) {

	if(pos == n) {
		print();
		return;
	}
	
	solve(pos + 1);
	 
	out.push_back(v[pos]);
	solve(pos + 1);
	out.pop_back();

}

int main()
{
	cin >> n;

	v.resize(n+1);

	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	solve(0);

	return 0;
}
