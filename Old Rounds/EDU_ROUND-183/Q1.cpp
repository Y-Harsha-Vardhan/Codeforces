#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int a; cin >> a;

        int r = a%3;
        if (r == 0) cout << 0 << "\n";
        else cout << 3-r << "\n";
    }
}