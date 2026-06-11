#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        ll minK = 0, maxK = 0;
        for (int i=0; i<n; i++) {
            ll valA = a[i]; ll valB = b[i];
            ll red1 = maxK - valA;  ll red2 = minK - valA;
            ll blue1 = valB - minK; ll blue2 = valB - maxK;

            maxK = max(red1, blue1);
            minK = min(red2, blue2);
        }

        cout << maxK << "\n";
    }
}