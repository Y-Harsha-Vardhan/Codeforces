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
        int minCalls = n;
        for (int i=0; i<n; i++) {
            int l=0, r=0;
            for (int j=0; j<n; j++) {
                if (a[j] < a[i]) l++;
                if (a[j] > a[i]) r++;
            }
            int curr = max(l, r);
            minCalls = min(minCalls, curr);
        }

        cout << minCalls << "\n";
    }
}