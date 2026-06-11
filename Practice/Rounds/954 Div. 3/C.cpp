#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string s; cin >> s;
        set<int> uniqInd;
        for (int i=0; i<m; i++) {
            int ind; cin >> ind;
            uniqInd.insert(ind-1);
        }
        string c; cin >> c;
        sort(c.begin(), c.end());

        int x=0; for (int id: uniqInd) s[id] = c[x++];
        cout << s << "\n";
    }
}