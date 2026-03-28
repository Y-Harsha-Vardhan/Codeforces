#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        int d = abs(x-y);
        ll ans = 0;

        if (d == 0) ans = 1; // only array
        else { // its factors
            for (int i=1; i*i<=d; i++) {
                if (d%i == 0) {
                    ans++;
                    if (i*i != d) ans++;
                }
            }   
        }

        cout << ans % 676767677 << "\n";
        for (int i=0; i<x; i++) cout << "1" << " ";
        for (int i=0; i<y; i++) cout << "-1" << " ";
        cout << "\n";
    }
}