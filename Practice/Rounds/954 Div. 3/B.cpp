#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> mat[i][j];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int mx=0;
                if (i>0) mx = max(mx, mat[i-1][j]);
                if (i<n-1) mx = max(mx, mat[i+1][j]);
                if (j>0) mx = max(mx, mat[i][j-1]);
                if (j<m-1) mx = max(mx, mat[i][j+1]);
                
                if (mat[i][j]>mx) mat[i][j] = mx;
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) cout << mat[i][j] << " ";
            cout << "\n";
        }
    }
}