
//Một dãy dấu ngoặc hợp lệ là một dãy các ký tự “(” và “)” được định nghĩa như sau:
//i) Dãy rỗng là một dãy dấu ngoặc hợp lệ có độ sâu bằng 0.
//ii) Nếu A là một dãy dấu ngoặc hợp lệ có độ sâu là k, thì (A) là một dãy dấu ngoặc hợp lệ có độ sâu là k cộng một.
//iii) Nếu A và B là hai dãy dấu ngoặc hợp lệ với độ sâu lần lượt là p và q, thì AB là một dãy dấu ngoặc hợp lệ có độ sâu bằng max của p và q.

//Độ dài của một dãy ngoặc là tổng số ký tự “(” và “)”.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

void print(string s) {
	cout << s << endl;
}

void solve(int pos, int openUsed, int closeUsed, int currDepth, int maxDepth, string s) {
    
    //bound 1
	if (maxDepth > k) return;

	if(pos == n) 
	{
		if(openUsed == closeUsed && maxDepth == k) {
			print(s);
		}
		return;
	}

	int pair = n / 2;

	int rem = n - pos + 1;
	int closeNeeded = openUsed - closeUsed;
    
    //bound 2
	if(closeNeeded > rem) return;

	if(openUsed < pair) {
		s.push_back('(');
		int curr = currDepth + 1;
		int cmax = max(curr, maxDepth);
		solve(pos + 1, openUsed + 1, closeUsed, curr, cmax, s);
		s.pop_back();
	}

	if(closeUsed < openUsed) {
		s.push_back(')');
		solve(pos + 1, openUsed, closeUsed + 1, currDepth - 1, maxDepth, s);
		s.pop_back();
	}

}

int main()
{
	cin >> n >> k;

	if (k < 0 || k > n/2) return 0;

	string s;
	solve(0, 0, 0, 0, 0, s);

	return 0;
}
