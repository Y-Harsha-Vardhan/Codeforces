#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MX = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<ll> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
        for (ll x: primes) {
            bool ok = false;
            for (ll i: a) if (i%x!=0) {ok=true; break;}
            if(ok) {cout << x << "\n"; break;}
        } 
    }
}