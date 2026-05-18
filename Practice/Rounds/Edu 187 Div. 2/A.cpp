#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m, d; cin >> n >> m >> d;
        int k = d/m, ans; 
        if (k == 0) ans = n;
        else {
            int a = n%(k+1), b = n/(k+1);
            if (a != 0) b++;
            ans = max(1, b);
        }
        cout << ans << "\n";
    }
}