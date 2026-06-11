#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {   
    int n; cin >> n;
    vector<ll> o, e;
    for (int i=0; i<n; i++) {
        ll val; cin >> val;
        if (val%2 != 0) o.push_back(val);
        else e.push_back(val);
    }

    int numO = o.size(), numE = e.size();
    if (numO == 0) {
        for (int k=1; k<=n; k++) cout << 0 << " ";
        cout << "\n";
        return;
    } 

    sort(e.rbegin(), e.rend());
    vector<ll> pe(numE+1, 0);
    for (int i=0; i<numE; i++) pe[i+1] = pe[i]+e[i];
    ll maxOdd = *max_element(o.begin(), o.end());
    vector<ll> ans; ans.reserve(n);
    for (int i=1; i <=n; i++) {
        int minX = max(1, i-numE);
        if (minX %2 == 0) minX++;

        if (minX > numO || minX >i) ans.push_back(0);
        else {
            int y = i-minX;
            ll s =maxOdd + pe[y];
            ans.push_back(s); 
        }
    }

    for (int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}