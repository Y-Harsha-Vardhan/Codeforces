#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, m, a, b; cin >> n >> m >> a >> b;
        bool x = (gcd(n, a) == 1);
        bool y = (gcd(m, b) == 1);
        bool z = (gcd(n, m) <= 2);

        cout << (x && y && z ? "YES" : "NO") << "\n";
    }
}