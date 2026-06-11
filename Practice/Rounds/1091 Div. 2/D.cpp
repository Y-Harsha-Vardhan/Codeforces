#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n+2); for (int i=1; i<=n; i++) cin >> a[i];
        vector<int> p(k+2); for (int i=1; i<=k; i++) cin >> p[i];
        int x = a[p[1]]; int pos = p[0]; p[k+1] = n+1;
        a[0] = a[n+1] = x;

        int S=0, X=0;
        for (int i=0; i<=k; i++) {
            int cnt=0; 
            for (int j=p[i]; j<p[i+1]; j++) if (a[j] != a[j+1]) cnt++;
            S += cnt; X = max(X, cnt);
        }
        
        cout << max(S/2, X) << "\n";
    }
}