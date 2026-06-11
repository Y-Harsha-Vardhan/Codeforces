#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n+1); for (int i=1; i<=n; i++) cin >> a[i];
        ll cnt = 0; int lim = sqrt(n);
        for (int v=1; v<=lim; v++) {
            for (int j=1; j<=n; j++) {
                if (a[j]>=v && a[j]<=n/v){
                    int i=j-v*a[j];
                    if (i>=1 && a[i]==v) cnt++;
                }
            }
            for (int i=1; i<=n; i++) {
                if (a[i]>v && a[i]<=n/v) {
                    int j=i+a[i]*v;
                    if (j<=n &&a[j]==v) cnt++;    
                }
            }
        }
        cout << cnt << "\n";
    }
}