//Cho trước một số nguyên dương N (N ≤ 100), hãy tìm một xâu chỉ gồm các ký tự A, B, C thỏa mãn 3 điều kiện:
// 1. Có độ dài N
// 2. Hai đoạn con bất kỳ liền nhau đều khác nhau (đoạn con là một dãy ký tự liên tiếp của xâu)
// 3. Có ít ký tự C nhất.

#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

int n;
int MIN;
vector<int> T;
vector<char> x, best;

void print() {
	for(int i = 0; i < n; ++i) {
		cout << best[i];
	}
	cout << endl;
	cout << MIN;
}

void update_best_result() {
	MIN = T[n-1];

	for(int i = 0; i < n; ++i) {
		best[i] = x[i];
	}
}

bool isSame(int pos, int l) {
	int j = pos - l;

    //int a = pos - 2*l + 1;
	//int b = pos - l + 1;
	for(int k = 0; k < l;  ++k) {
		//    cout << "x[pos - k]: " << x[pos - k] << " ";
		//    cout << "x[j - k]: " << x[j - k] << endl;
		if(x[pos - k] != x[j - k]) {
			return false;
		}
	}

	return true;
}

bool check(int pos) {
	int len = pos + 1;

	for(int i = 1; i <= len/2; ++i) {
		if(isSame(pos, i))
			return false;
	}

	return true;
}


void solve(int i) {
	for(char ch : {
	            'A', 'B', 'C'
	        }) {
		x[i] = ch;
		if(check(i)) {
			if(ch == 'C') T[i] = T[i-1] + 1;
			else T[i] = T[i-1];

			if( T[i] >= MIN ){
			  continue;  
			} 

			if(i == n - 1) {
				update_best_result();
			}
			else solve(i + 1);

		}
	}
}

int main()
{
	cin >> n;
	T.resize(n+1);

	x.resize(n+1);
	best.resize(n+1);

	T[0] = 0;
	//x[0] = 'A';
	MIN = n+1;
    cout << "F-MIN: " << MIN << endl;
	solve(0);
	print();

	return 0;
}
