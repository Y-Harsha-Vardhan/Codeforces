#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int m, s; cin >> m >> s;
        vector<int> b(m); set<int> st;
        int mx = 0;
        for (int i=0; i<m; i++) {
            cin >> b[i];
            st.insert(b[i]);
            mx = max(mx, b[i]);
        }

        for (int i=1; i<=mx; i++) if (!st.count(i)) s -= i;
        int cur = mx+1;
        while (s>0) {s-=cur; cur++;}
        
        if (s == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}