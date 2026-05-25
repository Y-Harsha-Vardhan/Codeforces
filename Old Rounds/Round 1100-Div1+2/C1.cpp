#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b; bool rev = false;
        for (int i=n-1; i>=0; i--) {
            ll val = rev ? -a[i] : a[i];
            if (val>0) {
                b.push_back(i+1);
                rev = !rev;
            }
        }

        int k = b.size(); cout << k << "\n";
        for (int i=0; i<k; i++) cout << b[i] << " ";
        cout << "\n";
    }
}