#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> cnt(k, 0); for (int i=0; i<n; i++) cnt[i%k] += s[i]-'0';
        bool pos=true;
        for (int i=0; i<k; i++) if (cnt[i]%2) {pos=false; break;}
        cout << (pos ? "YES\n" : "NO\n");
    }
}