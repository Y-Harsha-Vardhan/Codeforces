#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // int t; cin >> t;
    // while(t--){
    ll w,h,d; cin >> w >> h >> d;
    ll n; cin >> n;
    ll x = gcd(n, w); ll n1 = n/x;
    ll y = gcd(n1, h); ll n2 = n1/y;
    ll z = gcd(n2, d); ll n3 = n2/z;

    if (n3 == 1) cout << x-1 << " " << y-1 << " " << z-1 << "\n";
    else cout << "-1\n";
    //}
}