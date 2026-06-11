#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        for (int i=0; i<n-1; i++) {
            if (s[i] == 'R' && s[i+1] == 'L') break;
            ans++;
        }
        cout << ans+2 << "\n";
    }
}