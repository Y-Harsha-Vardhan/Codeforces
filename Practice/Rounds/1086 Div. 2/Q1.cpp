#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        vector<int> cnt(n*n + 1, 0);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int x; cin >> x;
                cnt[x]++; a[i][j] = x;
            }
        }

        if (*max_element(cnt.begin(), cnt.end()) <= n*n-n) cout << "YES\n";
        else cout << "NO\n";
    }
}