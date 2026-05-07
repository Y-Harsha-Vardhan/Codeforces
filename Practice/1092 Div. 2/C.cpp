#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; ll p, q; cin >> n >> k >> p >> q;
        vector<ll> a(n+1); for (int i=1; i<=n; i++) cin >> a[i];
        vector<ll> cost1(n+1), cost2(n+1);
        for (int i=1; i<=n; i++) {
            cost1[i] = (a[i]%p)%q;
            cost2[i] = (a[i]%q)%p;
        }

        vector<ll> best(n+1); for (int i=1; i<=n; i++) best[i] = min(cost1[i], cost2[i]);
        vector<ll> pref1(n+1, 0), pref2(n+1, 0), prefBest(n+1, 0);
        for (int i=1; i<=n; i++) {
            pref1[i] = pref1[i-1] + cost1[i];
            pref2[i] = pref2[i-1] + cost2[i];
            prefBest[i] = prefBest[i-1] + best[i];
        }

        ll ans = 1e18;
        for (int r=k; r<=n; r++) {
            int l = r-k+1; 
            ll segCost1 = pref1[r]-pref1[l-1], segCost2 = pref2[r]-pref2[l-1];
            ll segCost = min(segCost1, segCost2);
            ll outCost = prefBest[l-1] + (prefBest[n] - prefBest[r]);
            ans = min(ans, segCost+outCost);
        }

        cout << ans << "\n";
    }
}