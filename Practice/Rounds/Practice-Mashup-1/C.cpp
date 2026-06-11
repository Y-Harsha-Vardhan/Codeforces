#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 676767677;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        ll ans = 0;

        for (int i=0; i<n; i++){
            if (a[i] != 1) ans += a[i];
            ans %= MOD;
        }
        if (ans == 0) cout << 1 << "\n";
        else if (a[n-1] == 1) cout << ans+1 << "\n";
        else cout << ans << "\n";
    }
}
