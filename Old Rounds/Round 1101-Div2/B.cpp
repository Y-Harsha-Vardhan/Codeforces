#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        ll currSum=0, minH=5e18;
        for (int i=1; i<=n; i++) {
            ll x = a[i-1];
            currSum += x;
            ll maxPosH = currSum/i;
            if (maxPosH < minH) minH = maxPosH;

            cout << minH << " ";
        }
        cout << "\n";
    }
}