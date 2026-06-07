#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> s(n); 
        ll ans = 0; priority_queue<ll> bonus;
        for (int i=0; i<n; i++) {
            ll x; cin >> x;
            if (x > 0) bonus.push(x);
            else if (!bonus.empty()) {
                ans += bonus.top();
                bonus.pop();
            }
        }

        cout << ans << "\n";
    }
}