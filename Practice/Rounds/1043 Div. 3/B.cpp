#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fact;
void preComp(vector<ll>& fact) {
    ll x = 10;
    for (int i=1; i<18; i++) {
        fact.push_back(x+1);
        x = x*10;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preComp(fact);
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        int k = fact.size();
        vector<ll> ans;
        
        for (int i=k-1; i>=0; i--) {
            ll f = fact[i];
            if (n % f == 0) ans.push_back(n/f);
        }

        if (ans.size() == 0) cout << 0 << "\n";
        else {
            cout << ans.size() << "\n";
            for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";
            cout << "\n";
        }
    }
}