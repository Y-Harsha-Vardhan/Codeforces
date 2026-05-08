#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n+2); for (int i=1; i<=n; i++) cin >> a[i];
        vector<int> p(k); for (int i=0; i<k; i++) cin >> p[i];
        int x = a[p[0]]; int pos = p[0];
        a[0] = a[n+1] = x;

        int cntL = 0, cntR = 0;
        for (int i=0; i<pos; i++) if (a[i] != a[i+1]) cntL++;
        for (int i=pos; i<n+1; i++) if (a[i] != a[i+1]) cntR++;
        
        cout << max(cntL, cntR) << "\n";
    }
}