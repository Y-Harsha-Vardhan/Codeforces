#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int k; cin >> k; bool win1=false, win2=false;
        int a1, b1; cin >> a1 >> b1; if (a1>b1) win1 = true;
        int a2, b2; cin >> a2 >> b2; if (a2>b2) win2 = true;
        int a = a1+a2, b = b1+b2;

        if (a-b >= k) cout << "NO\n";
        else cout << "YES\n";
    }
}