#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m, k=0; cin >> n >> m;
        vector<int> prefRowSum(n), rowSum(n);
        vector<vector<int>> grid(n, vector<int>(m)); 
        for (int i=0; i<n; i++) {
            int rowCnt=0;
            for (int j=0; j<m; j++) {
                cin >> grid[i][j];
                k += grid[i][j]; 
                rowCnt += grid[i][j];
                if (j == m-1) {
                    prefRowSum[i] = k;
                    rowSum[i] = rowCnt;
                }
            }
        }

        int x=k/2, r=0;
        ll ans = 1LL*x*(k-x);
        while (r<n && prefRowSum[r]<x) r++;
        int above = (r==0 ? 0: prefRowSum[r-1]);
        int need = x-above;

        int col = 0;
        if (need > 0 && r<n) {
            int targPref = rowSum[r] -need;
            if (targPref>0) {
                int cnt = 0;
                for (int j=0; j<m; j++) {
                    if (grid[r][j]==1) cnt++;
                    col = j+1;
                    if (cnt == targPref) break;
                }
            }
        }

        cout << ans << "\n";
        string path;
        path.append(r, 'D');
        path.append(col, 'R');
        path.append(1, 'D');
        path.append(m-col, 'R');
        path.append(n-r-1, 'D');

        cout << path << "\n";

    }
}