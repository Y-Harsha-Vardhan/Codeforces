#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> adj(n+1);
        for (int i=0; i<n-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d(n+1, 0);
        vector<int> cnt(n+1, 0);
        vector<int> childCnt(n+1, 0);
        vector<int> p(n+1, 0);
        queue<int> q; 
        q.push(1); d[1]=0;
        cnt[0] = 1;
        int maxD = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            maxD = max(maxD, d[u]);
            for (int v : adj[u]) {
                if (v!= p[u]) {
                    d[v] = d[u]+1;
                    cnt[d[v]]++;
                    p[v] = u;
                    childCnt[u]++; q.push(v);
                }
            }
        }
        int ans =0;
        for (int i=0; i<=maxD; i++) ans = max(ans, cnt[i]);
        for (int u=1; u<=n; u++) {
            int dep = d[u];
            if (childCnt[u] > 0) {
                if (childCnt[u] == cnt[dep+1]) ans = max(ans, cnt[dep+1]+1);
            }
        }
        cout << ans << "\n";
    }
}