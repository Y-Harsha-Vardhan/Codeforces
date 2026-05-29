#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> count25(ll n) {
    int two=0, five=0;
    while (n%2 == 0) {two++; n/=2;}
    while (n%5 == 0) {five++; n/=5;}
    return {two, five};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        auto [two, five] = count25(n); ll k=1;
        while (two<five && k*2<=m) {k *= 2; two++;}
        while (five<two && k*5<=m) {k *= 5; five++;}
        while (k*10<=m) k*=10;
        k *= m/k;

        cout << n*k << "\n";
    }
}