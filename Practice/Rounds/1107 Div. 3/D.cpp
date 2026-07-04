#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> prefA(n); for (int i=0; i<n; i++) {
            if (i==0) cin >> prefA[i];
            else {
                ll x; cin >> x;
                prefA[i] = x + prefA[i-1];
            }
        }
        vector<ll> prefB(n); for (int i=0; i<n; i++) {
            if (i==0) cin >> prefB[i];
            else {
                ll x; cin >> x;
                prefB[i] = x + prefB[i-1];
            }
        }

        bool isPos = true;
        for (int i=0; i<n; i++) {
            if (prefB[i]<prefA[i]) {isPos=false; break;}
        }
        cout << (isPos ? "YES\n" : "NO\n");
    }
}