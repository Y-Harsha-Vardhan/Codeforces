#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int prot = 0;
        int lastONE = -1;
        for (int i=0; i<n; i++) {
            if (s[i]=='1') {
                int winStart = max(0, i-k+1);
                if (lastONE < winStart) prot++;
                lastONE = i;
            }
        }
        cout << prot << "\n";
    }
}