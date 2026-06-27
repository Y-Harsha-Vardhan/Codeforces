#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll k, x, kk; cin >> k >> x; kk = 1ll << k;
        if (!x || x==kk*2) {cout << "-1\n"; continue;}
        ll y = kk*2-x; vector<int> ans; ans.clear();
        while (x != kk) {
            if (x>y) ans.push_back(2), x-=y, y*=2;
            else ans.push_back(1), y-=x, x*=2;
        }

        cout << ans.size() << "\n";
        while (!ans.empty()) cout << ans.back() << " ", ans.pop_back();
        cout << "\n";
    }
}