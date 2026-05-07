#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

int Xbits[32], Ybits[32];
bool vis[32][3][3];
ll mem[32][3][3];
pair<int, int> c[32][3][3];

ll solveDP(int i, int cx, int cy) {
    if (i<0) return 0;
    if (vis[i][cx][cy]) return mem[i][cx][cy];

    ll minCst = INF;
    pair<int, int> best = {-1, -1};
    vector<pair<int, int>> opt = {{0, 0}, {0, 1}, {1, 0}};

    for (auto p: opt) {
        int bp = p.first, bq = p.second;
        int vx = Xbits[i], vy = Ybits[i];

        int nx = cx, ny = cy;
        if (cx == 0) {
            if (bp <vx) nx = 1;
            else if (bp > vx) nx = 2;
        }
        if (cy == 0) {
            if (bq < vy) ny =1;
            else if (bq> vy) ny = 2;
        }

        ll curCst = 0;
        ll bitVal = (1LL << i);

        if (nx == 2) {
            if (bp==1 && vx==0) curCst += bitVal;
            else if (bp== 0 && vx==1) curCst -= bitVal;
        }
        else if (nx == 1) {
            if (vx==1 && bp== 0) curCst += bitVal;
            else if (vx==0 && bp==1) curCst -= bitVal; 
        }

        if (ny== 2) { 
            if (bq==1 && vy==0) curCst += bitVal;
            else if (bq==0 && vy==1) curCst -= bitVal;
        }
        else if (ny == 1) { 
            if (vy== 1 && bq ==0) curCst += bitVal;
            else if (vy ==0 && bq==1) curCst -= bitVal;
        }

        ll rem = solveDP(i-1, nx, ny);
        if (rem != INF) {
            ll tot = curCst+ rem;
            if (tot < minCst) {
                minCst = tot;
                best = {bp, bq};
            }
        }
    }
    
    vis[i][cx][cy] = true;
    c[i][cx][cy] = best;
    return mem[i][cx][cy] = minCst;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        for (int k=0; k<=30; k++) {
            Xbits[k] = (x>>k)&1;
            Ybits[k] = (y>>k)&1;
        }

        for (int i=0; i<=30; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) vis[i][j][k] = false;
            }
        }

        solveDP(30, 0, 0);
        ll p=0, q=0;
        int curCX=0, curCY=0;
        for (int i=30; i>=0; i--) {
            pair<int, int> pi = c[i][curCX][curCY];
            int bp = pi.first;
            int bq = pi.second;

            if (bp) p |= (1LL << i);
            if (bq) q |= (1LL << i);

            int vx = Xbits[i], vy = Ybits[i];
            if (curCX==0) {
                if (bp<vx) curCX = 1;
                else if (bp>vx) curCX = 2;
            }
            if (curCY==0) {
                if (bq<vy) curCY =1;
                else if (bq>vy) curCY=2;
            }
        } 

        cout << p << " " << q << "\n";
    }
}