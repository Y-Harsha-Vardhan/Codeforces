#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x = n/3, rem=n%3;

        if (rem == 0) cout << x << " " << x+1 << " " << x-1 << "\n";
        else if (rem == 1) cout << x << " " << x+2 << " " << x-1 << "\n";
        else cout << x+1 << " " << x+2 << " " << x-1 << "\n";
    }
}