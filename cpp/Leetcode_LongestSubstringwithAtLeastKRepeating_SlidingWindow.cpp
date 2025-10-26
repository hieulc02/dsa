//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
//if no such substring exists, return 0.
//s consists of only lowercase English letters.

//sliding window

//the ideal solution covers all possible sets of letters present in the string s, which contains between 1 and 26
//sweep over the string's indicates, for each t which represent position of letters, we find the best result so the problem reduce find the substring with exactly t letters

#include <bits/stdc++.h>
using namespace std;

int longestSubstring(const string &s, int k) {
    int n = (int)s.size();
    if (k <= 1) return n;
    if (k > n) return 0;

    int best = 0;

    for(int t = 1; t <= 26; ++t){
        
        int distinct = 0;
        int atLeastK = 0;
        int i = 0, j = 0;
        int cnt[26] = {0};
        
        while(j < n){
            int cj = s[j] - 'a';
            
            ++cnt[cj];
            if(cnt[cj] == 1) distinct++;
            
            if(cnt[cj] == k) atLeastK++;
            
            while(distinct > t){
                int ci = s[i] - 'a';
                
                if(cnt[ci] == k) atLeastK--;
                cnt[ci]--; 
                if(cnt[ci] == 0) distinct--;
            
                i++;    
            }
          
            if(distinct == t && atLeastK == t){
                best = max(best, j - i + 1);
            }
            
            j++;
        }
        
    }
    
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; int k;
    if (cin >> s >> k) {
        cout << longestSubstring(s, k) << "\n";
    }
    return 0;
}
