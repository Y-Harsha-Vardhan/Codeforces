#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll k = n/12; int r = n%12;
        if (r<=9 || r==11) cout << r << " " << n-r << "\n";
        else if (r== 10) {
            if (n==10) cout << "-1\n";
            else cout << 22 << " " << n-22 << "\n";
        }
    }
}