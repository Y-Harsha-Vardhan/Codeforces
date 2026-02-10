#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, x, y; cin >> n >> x >> y;
        vector<ll> a(n); 

        ll Sall=0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            Sall += a[i]/x;
        }

        for (int i=0; i<n; i++) {
            ll s = Sall - a[i]/x;
            a[i] += s*y;
        }

        auto maxIt = max_element(begin(a), end(a));
        ll maxVal = *maxIt;
        cout << maxVal << "\n";

    }
}