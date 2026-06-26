#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<ll> cnt(3); cnt[0]=1;
        ll tot=1, ans=0; int x=0, y=0;
        char pre='#';
        for (char c: s) {
            x += (c=='0'? 1 : -1);
            x = (x%3 + 3)%3;
            y = (c==pre ? 1: y+1);
            pre = c;
            ans += tot - cnt[x];
            cnt[x]++; tot++;
            ans -= (y-1)/2;
        }

        cout << ans << "\n";
    }
}