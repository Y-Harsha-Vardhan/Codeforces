#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        // ai . 2^aj = aj . 2^ai -> ai/aj = 2^(ai-aj)
        // b = a.2^k -> k = a.(2^k-1) -> k = 0, 1(a=1) => a=b or a=1,b=2
        ll ans=0; map<int,int> freq;
        for (int i=0; i<n; i++) {
            ll x; cin >> x;
            ans += freq[x];
            if (x == 1) ans += freq[2];
            else if (x == 2) ans += freq[1];
            freq[x]++;
        }

        cout << ans << "\n";
    }
}