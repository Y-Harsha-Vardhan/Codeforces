#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n >> a >> b;
        ll full = n/3, rem = n%3;
        ll cost = full*min(b, 3*a);
        if (rem > 0) cost += min(b, rem*a);
        cout << cost << "\n";
    }
}