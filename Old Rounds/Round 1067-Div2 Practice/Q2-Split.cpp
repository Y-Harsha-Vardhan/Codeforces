#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n);
        for (int i=0; i<2*n; i++) cin >> a[i];

        vector<int> count(2*n+1);
        for (auto &x : a) count[x]++;
        int x = 0, y = 0, z = 0;
        for(int i=1; i<=2*n; i++) {
            if (count[i] == 0) continue;
            if (count[i] & 1) x++;
            else if (count[i] % 4) y++;
            else z++;
        }

        int ans = x + 2*y + 2*z;
        if ((z & 1) && x==0) ans -= 2;
        cout << ans << "\n";
    }
}