#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s; // divisibility by 4 is last 2 digits: 4, 12, 24, 32, 44.
        int rem = 0, x, y, z, n = s.length();
        for (char c: s) if (c == '4') rem++;
        int cnt13 = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '1' || s[i] == '3') cnt13++;
            else if (s[i] == '2') if (cnt13 >0) {rem++; cnt13--;}
        }

        cout << rem << "\n";        
    }
}