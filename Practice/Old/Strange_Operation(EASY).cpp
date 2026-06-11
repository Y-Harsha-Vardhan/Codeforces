#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n);
        for (int i=0; i<n; i++) cin >> p[i];
        
        vector<int> pos(n+1);
        for (int i=0; i<n; i++) pos[p[i]] = i;

        for (int cnt=1; cnt<=n; cnt++) {
            int curr = n;
            for (int i=cnt, mn = n; i<=n; i++) {
                if (pos[i] < mn) {
                    mn = pos[i];
                    if ((i & 1) == (cnt & 1)) curr = pos[i];
                }
            }

            int val = p[curr];
            p[curr] = cnt;
            for (int i=cnt; i<val; i++) p[pos[i]]++;
            for (int i=val; i>cnt; i--) pos[i] = pos[i-1];

            pos[cnt] = curr;
        }

        for (int i=0; i<n; i++) cout << p[i] << " ";
        cout << endl;
    }

    return 0;
}