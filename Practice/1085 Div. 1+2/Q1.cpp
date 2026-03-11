#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int existing = 0; for (int i=0; i<n; i++) if (s[i] == '1') existing++;
        int alt = 0; for (int i=0; i<n-2; i++) if (s[i] == '1' && s[i+1] == '0' && s[i+2] == '1') {alt++; s[i+1] = '1';}

        int mx = existing + alt;
        int mn = mx;
        for (int i=0; i<n-2; i++) {
            if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '1') {
                mn--;
                s[i+1] = '0';
            }
        }

        cout << mn << " " << mx << "\n"; 
    }
}