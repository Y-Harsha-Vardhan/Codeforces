#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int l, a, b; cin >> l >> a >> b;
        vector<bool> vis(l, false);
        int cur = a, mx = a;
        while (!vis[cur]) {
            vis[cur] = true;
            mx = max(mx, cur);
            cur = (cur + b)%l;
        }
        cout << mx << "\n";
    }
}