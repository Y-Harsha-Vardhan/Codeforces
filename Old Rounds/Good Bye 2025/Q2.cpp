#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        string r; cin >> r;
        int n = r.length(), op = 0;
        if (r[0] == 'u') {r[0]='s'; op++;}
        if (r[n-1] == 'u') {r[n-1]='s'; op++;}

        for (int i=0; i<n-1; i++) {
            if (r[i]=='u' && r[i+1]=='u') {
                r[i+1] = 's'; op++;
            }
        }
        cout << op << "\n";
    }
}