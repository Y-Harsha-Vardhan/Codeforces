#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n, x, s; cin >> n >> x >> s;
        string u; cin >> u; 
        ll l=0, r=0, ans=0;
        for (char c: u) {
            if (c=='A') {
                if (x*s==ans) continue;
                ans++;
                if (ans > l*s) l++;
                r = min(x, r+1);
            } else if (c == 'I') {
                if (l == x) continue;
                ans++; l++;
                r = min(x, r+1);
            } else if (c == 'E') {
                if (ans == r*s) continue;
                ans++;
                if (ans > l*s) l++;
            }
        }
        cout << ans << "\n";
    }
}