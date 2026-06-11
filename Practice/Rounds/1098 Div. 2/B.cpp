#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
        if (n<=3) cout << 1 << "\n";
        else cout << min(abs(x1-x2), n - abs(x1-x2)) + k << "\n";
    }
}