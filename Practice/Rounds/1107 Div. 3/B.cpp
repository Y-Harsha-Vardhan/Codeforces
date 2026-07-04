#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        string s = to_string(x); int n = s.length();
        ll ans = 1; for (int i=0; i<n; i++) ans *= 10;
        ans++; 
        cout << ans << "\n";
    }
}