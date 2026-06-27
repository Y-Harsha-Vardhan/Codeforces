#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> cnt(m, 0); int t=0;
        vector<vector<int>> v(n);
        for (int i=0; i<n; i++) {
            int l; cin >> l;
            v[i].resize(l);
            for (int j=0; j<l; j++) {
                int x; cin >> x; x--;
                if (cnt[x]==0) t++;
                cnt[x]++;
                v[i][j]=x;
            }
        }

        int ans = (t==m);
        for (int i=0; i<n; i++) {
            for (int x: v[i]) {
                cnt[x]--;
                if (cnt[x] == 0) t--;
            }

            if (t==m) ans++;
            for (int x: v[i]) {
                if (cnt[x]==0) t++;
                cnt[x]++;
            }
        }

        cout << (ans>=3 ? "YES\n" : "NO\n");
    }
}