#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 2e18;

struct DiagMax {
    ll m1 = -INF, m2 = -INF;
    int pos1X = -1, pos1Y = -1;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<ll>> pref(n, vector<ll>(m, -INF));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ll up = (i==0) ? -INF : pref[i-1][j];
                ll left = (j==0)? -INF: pref[i][j-1];

                if (i==0 && j==0) pref[i][j] = a[i][j];
                else pref[i][j] = max(up, left) + a[i][j]; 
            }
        }

        vector<vector<ll>> suff(n, vector<ll>(m, -INF));
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                ll down = (i==n-1) ? -INF: suff[i+1][j];
                ll right = (j==m-1) ? -INF: suff[i][j+1];

                if (i==n-1 && j==m-1) suff[i][j] = a[i][j];
                else suff[i][j] = max(down, right) + a[i][j];
            }
        }

        vector<DiagMax> dmax(n+m-1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int d = i+j; 
                ll v = pref[i][j]+suff[i][j] -a[i][j];
                if (v>dmax[d].m1) {
                    dmax[d].m2 = dmax[d].m1;
                    dmax[d].m1 = v;
                    dmax[d].pos1X = i;
                    dmax[d].pos1Y = j;
                }
                else if (v > dmax[d].m2) dmax[d].m2 = v;
            }
        }

        ll ans = INF;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int d= i+j;
                ll Mij = -INF;

                if (dmax[d].pos1X == i && dmax[d].pos1Y==j) Mij = dmax[d].m2;
                else Mij = dmax[d].m1;

                ll valIJ = pref[i][j] + suff[i][j] - a[i][j];
                ll Sij = max(Mij, valIJ-2*a[i][j]);
                ans = min(ans, Sij);
            }
        }

        cout << ans << "\n";
    }
}