#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> h(n); for (int i=0; i<n; i++) cin >> h[i];
        for (int i=0; i<n; i++) {
            vector<int> L(n, 0), R(n, 0);
            int currMax=0;
            for (int k=1; k<n; k++) {
                currMax = max(currMax, h[(i+k-1)%n]);
                L[k] = currMax;
            } currMax=0;
            for (int k=n-1; k>0; k--) {
                currMax = max(currMax, h[(i+k)%n]);
                R[k] = currMax;
            }

            ll totVol = 0;
            for (int k=1; k<n; k++) totVol += min(L[k], R[k]);
            cout << totVol << " ";
        }
        cout << "\n";
    }
}