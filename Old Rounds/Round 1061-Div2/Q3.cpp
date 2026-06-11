#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<long long> f(n+1, 0);
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            if (a <= n) f[a]++;
        }

        vector<long long> prefixFreq(n+1, 0);
        for (int i=1; i<=n; i++) prefixFreq[i] = prefixFreq[i-1] + f[i];

        int maxBeauty = 1;
        for (int d=n; d>=2; d--) {
            long long lim = min((long long)n, 4LL*d-1);
            long long totLess = prefixFreq[lim];
            long long mult = 0;
            if (d <= n) mult += f[d];
            if (2LL*d <= n) mult += f[2*d];
            if (3LL*d <= n) mult += f[3*d];

            long long eraseCount = totLess - mult;
            if (eraseCount <= k) {maxBeauty = d; break;}
        }

        cout << maxBeauty << "\n";
    }
}