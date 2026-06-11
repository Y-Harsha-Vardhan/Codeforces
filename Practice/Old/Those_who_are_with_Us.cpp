#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int mx = -1, cnt = 0;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int x; cin >> x; mat[i][j] = x;
                if (x > mx) {mx = x; cnt = 1;}
                else if (x == mx) cnt++;
            }
        }

        vector<int> r(n), c(m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) 
                if (mat[i][j] == mx) {r[i]++; c[j]++;}
        }

        bool isPos = false;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (r[i]+c[j] - (mat[i][j]==mx) == cnt) isPos = true;
            }
        }

        cout << mx - (int)isPos << "\n";
    }
}