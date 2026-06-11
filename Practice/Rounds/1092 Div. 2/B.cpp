#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll ct,ch,cu; cin >> ct >> ch >> cu;
        if (ct > cu + 2*ch) cout << 2*ct + 3*ch + 2*cu + 1 << "\n";
        else cout << 2*ct + 3*ch + 3*cu - min(ct, cu) << "\n";
    }
}