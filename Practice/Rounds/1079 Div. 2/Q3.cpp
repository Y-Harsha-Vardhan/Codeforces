#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll p, q; cin >> p >> q;
        if (p<q && 3*p>=2*q) cout << "Bob\n";
        else cout << "Alice\n";
    }
}