#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll x, y; cin >> x >> y; // x = 2a+3b+4c, y = a-c => x-2y = 3b+6c ; x+4y = 6a + 3b
        bool pos1 = ((x+y)%3 == 0);
        bool pos2 = ((y>=-x/4) && (y<=x/2));
        cout << ((pos1 && pos2) ? "YES\n" : "NO\n");
    }
}