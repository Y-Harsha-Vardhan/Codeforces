#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll x, y; cin >> x >> y;
        ll k = y/x;
        if (k <= 2) cout << "NO\n";
        else cout << "YES\n";
    }
}