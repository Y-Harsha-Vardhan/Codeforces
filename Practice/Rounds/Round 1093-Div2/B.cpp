#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n); int mx = 0, cnt = 0, prev = -1;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (x == prev) cnt++;
            else {
                cnt = 1;
                prev = x;
            }
            mx = max(mx, cnt);
        }
        cout << (mx >= m ? "NO\n" : "YES\n");
    }
}