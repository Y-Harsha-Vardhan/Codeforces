#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        vector<int> a; int negSum = 0;
        for (int i=0; i<7; i++) {
            int x; cin >> x;
            negSum -= x;
            a.push_back(x);
        }

        int mx = -1e9;
        for (int i=0; i<7; i++) {
            mx = max(mx, negSum + 2*a[i]);
        }
        cout << mx << "\n";
    }
}