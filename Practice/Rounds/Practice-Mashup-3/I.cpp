#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll h, k; cin >> n >> h >> k;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<ll> prefSum(n); prefSum[0] = a[0];
        for (int i=1; i<n; i++) prefSum[i] = a[i]+prefSum[i-1];
        ll sum = prefSum[n-1]; ll numMags = (h-1)/sum; 
        ll ans = (n+k)*numMags; h -= numMags*sum;
        if (h<=0) {cout << ans << "\n"; continue;}

        vector<ll> maxRight(n); maxRight[n-1] = a[n-1];
        for (int i=n-2; i>=0; i--) maxRight[i] = max(maxRight[i+1], a[i]);
        ll minLeft = a[0];
        for (int i=0; i<n; i++) {
            minLeft = min(minLeft, a[i]);
            ll curSum = prefSum[i] - minLeft + maxRight[i+1];
            if (h<=curSum || h<=prefSum[i]) {
                cout << ans + i+1 << "\n";
                break;
            }
        }
    }
}