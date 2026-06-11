#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> b(n); 
        int c = 0; ll s = 0;
        for (int i=0; i<n; i++) {
            cin >> b[i];
            if (b[i] > 0) c++;
            s += b[i];
        }

        cout << c - max(0LL, (ll)n-1-s+c) << "\n";
    }
}