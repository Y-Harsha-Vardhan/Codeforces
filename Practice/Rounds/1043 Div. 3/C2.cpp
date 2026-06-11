#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> cost;
    ll c=3, cnt=1;
    for (int i=0; i<21; i++) {
        cost.push_back(c);
        c = c*3 + cnt;
        cnt *= 3;
    }
    
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> tr;
        ll minK=0;

        while (n) {
            tr.push_back(n%3);
            minK += n%3;
            n/=3;
        }

        if (minK > k) {cout << -1 << "\n"; continue;}
        k -= minK; k/=2;
        for (int i=(int)tr.size()-1; i>=1; i--) {
            if (tr[i] <=k) {
                tr[i-1] += 3*tr[i];
                k -= tr[i];
                tr[i] = 0;
            }
            else {
                tr[i-1] += k*3;
                tr[i] -= k;
                break;
            }
        }

        ll ans=0; for (int i=(int)tr.size()-1; i>=0; i--) ans += cost[i]*tr[i];
        cout << ans << "\n";
    }
}