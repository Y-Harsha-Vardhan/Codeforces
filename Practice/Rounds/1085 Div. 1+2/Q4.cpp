#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9
vector<vector<int>> adj;
int n, k, v;

int dfs(int v, int p=-1) {
    int l1 = INF, l2 = INF;
    for (int u: adj[v]) {
        if (u!=p) {
            int g = dfs(u, v);
            if (g<l2) swap(l2, g);
            if (l2<l1) swap(l1, l2);
        }
    }

    if (l1 == INF) return 0;
    else if (l2 == INF) return 1+l1;
    else {
        int s = 1+l1;
        if (l1+l2 < k) s=0;
        return s;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        cin >> n >> k >> v;
        adj = vector<vector<int>>(n+1);
        for (int i=1; i<n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << (dfs(v) ? "NO" : "YES") << "\n";
    }
}