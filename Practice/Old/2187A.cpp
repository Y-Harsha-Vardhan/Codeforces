    #include <algorithm>
    #include <bits/stdc++.h>
    #include <vector>
    using namespace std;
    typedef long long ll;
    
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int t; cin >> t;
        while(t--){
            int n; cin >> n;
            vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
            vector<ll> b = a; sort(b.begin(), b.end());

            ll mx = 2e18; bool isSorted = true;
            for (int i=0; i<n; i++) {
                if (a[i] != b[i]) {
                    isSorted = false;
                    ll maxDiff = max(a[i]-b.front(), b.back()-a[i]);
                    mx = min(mx, maxDiff);
                }
            }

            if (isSorted) cout << -1 << "\n";
            else cout << mx << "\n";
        }
    }