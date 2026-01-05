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
        vector<ll> suf(n+1, 0); for (int i=n-1; i>=0; i--) suf[i] = suf[i+1]+a[i];

        ll mxVal = -suf[1], curSum = 0;
        for (int i=1; i<n; i++) {
            ll rSum = suf[i+1];
            ll score = a[0]+curSum-rSum;
            if (score > mxVal) mxVal = score;

            curSum += abs(a[i]);
        }
        cout << mxVal << "\n";
    }
}