#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> fill(n+2, false); fill[a[0]] = true; bool pos = true;
        for (int i=1; i<n; i++) {
            int x = a[i]; int l = x-1, r = x+1;
            bool neigh = fill[l] || fill[r];

            if (!neigh) {pos = false; break;}
            fill[x] = true;
        }

        cout << (pos ? "YES\n" : "NO\n");
    }
}