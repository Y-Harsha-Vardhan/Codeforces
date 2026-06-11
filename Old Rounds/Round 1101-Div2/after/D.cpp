#include <bits/stdc++.h>
using namespace std;

struct Move{int disk, from, to;};
void moveall(int k, int s, int t, const vector<int>& a, vector<Move>& ops) {
    if (k<=0) return;
    int u = 6-s-t;
    if (a[k-1] == 0) {
        moveall(k-1, s, u, a, ops);
        ops.push_back({k,s,t});
        moveall(k-1, u, t, a, ops);
    } else {
        moveall(k-1-a[k-1], s, u, a, ops);
        ops.push_back({k,s,t});
        moveall(k-1-a[k-1], u,s,a, ops);
        moveall(k-1, s, t, a, ops);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        bool ok=true;
        for (int i=0; i<n; i++) if (a[i]>i) ok=false;
        if (!ok) {cout << "NO\n"; continue;}
        cout << "YES\n";
        vector<Move> ops; moveall(n, 1, 3, a, ops);
        cout << ops.size() << "\n";
        for (const Move& p: ops) cout << p.disk << " " << p.from << " " << p.to << "\n";
    }
}