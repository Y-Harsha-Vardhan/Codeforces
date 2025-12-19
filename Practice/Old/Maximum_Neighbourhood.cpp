#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a = 3*n*n - n - 1;
        int b = 4*n*n - n - 4;
        int c = 5*(n*n - n - 1);

        int ans = max(max(a, b), c);
        if (n == 2) ans = a;
        cout << ans << "\n";
    }
}