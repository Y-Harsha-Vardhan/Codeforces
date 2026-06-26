#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n=s.length(); bool inf = false;
        int cntL=0, cntR=0;
        for (int i=0; i<n-1; i++) if (s[i]!='<' && s[i+1]!='>') {inf=true; break;}
        for (int i=0; i<n; i++) {
            if (s[i]=='<') cntL++;
            else if (s[i]=='>') cntR++;
        }
        cout << (inf ? -1 : n-min(cntL, cntR)) << "\n";
    }
}