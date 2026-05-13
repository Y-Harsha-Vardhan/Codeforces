#include <algorithm>
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
        vector<int> b(n+1); for (int i=1; i<=n; i++) cin >> b[i];
        
        sort(a.begin()+1, a.end(), greater<int>());
        int h=0, sum=0; ll ans = 0;
        for (int i=1; i<=n; i++) {
            while (h<n && sum+b[h+1] <= i) {h++; sum += b[h];}
            ans = max(ans, a[i]*1ll*h);
        }
        cout << ans << "\n";
    }
}