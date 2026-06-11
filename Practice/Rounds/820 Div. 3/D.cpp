#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> x(n); for (int i=0; i<n; i++) cin >> x[i];
        vector<ll> y(n); for (int i=0; i<n; i++) cin >> y[i];
        vector<pair<ll, int>> diff(n); for (int i=0; i<n; i++) diff[i] = {y[i]-x[i], i};
        sort(diff.rbegin(), diff.rend());

        int j=n-1, cnt=0;
        for (int i=0; i<n; i++) {
            while (j>i && diff[i].first + diff[j].first < 0) j--;
            if (j<=i) break;
            cnt++; j--;
        }

        cout << cnt << "\n";
    }
}