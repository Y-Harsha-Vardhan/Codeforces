#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> up(26, 0), low(26, 0);
        for (char& c: s) {
            if ('A'<=c && 'Z'>=c) up[c-'A']++;
            else low[c-'a']++;
        }

        int ans=0; 
        for (int i=0; i<26; i++) {
            int p = min(up[i], low[i]);
            ans += p;
            low[i] -= p; up[i] -= p;
            int extra = min(k, max(up[i], low[i])/2);
            k -= extra; ans += extra;
        }

        cout << ans << "\n";
    }
}