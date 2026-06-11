#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<ll> P(n+1, 0);
        for (int i=0; i<n; i++) P[i+1] = P[i] + a[i];
        for (int k=0; k<q; k++) {
            int l, r; ll x; cin >> l >> r >> x;
            int curr = l;
            int clears = 0;
            ll currSum = 0;
            
            int prevLen = 1;
            while (curr <= r) {
                ll remSum = P[r] - P[curr-1];
                if (remSum < x) {currSum = remSum; break;}
                ll trgt = P[curr-1] + x;

                int srchStrt = min(r, curr + prevLen-1);
                auto it = lower_bound(P.begin()+ srchStrt, P.begin()+r+1, trgt);
                int endInd = distance(P.begin(), it);
                int len = endInd - curr + 1;
                prevLen = len;

                int maxP = (r-curr + 1)/len;
                int bestP = 1;
                int low = 1, high = maxP;
                while (low <= high) {
                    int mid = low + (high-low)/2;
                    int s = curr + (mid-1)*len;
                    int e = curr + mid*len -1;

                    if (P[e] -P[s-1] >= x) {
                        bestP = mid;
                        low = mid+1;
                    }
                    else high = mid -1;
                }
                clears += bestP;
                curr += bestP * len;
            }
            cout << clears << " " << currSum << "\n";
        }
    }
}