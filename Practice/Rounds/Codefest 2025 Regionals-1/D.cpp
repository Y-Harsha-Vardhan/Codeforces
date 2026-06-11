#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << "YES\n";
        vector<vector<ll>> a;
        if (n&1) {
            a.push_back({1, 3, 1});
            for (ll i=2; i<n; i+=2) a.push_back({2, 4, i, i+1});
        }

        else {
            for (ll i=1; i<n; i+=2) a.push_back({2, 4, i, i+1});
        }

        cout << a.size() << "\n";
        for (auto& row: a) {
            for (size_t i=0; i<row.size(); i++) cout << row[i] << " ";
            cout << "\n";
        }
    }
}