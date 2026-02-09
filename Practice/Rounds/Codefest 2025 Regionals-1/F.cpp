#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int ans[MAXN], G[MAXN], spf[MAXN];
bool seen[2*MAXN];

int cntTrailZeros(int n) {
    if (n==0) return 0;
    else return  __builtin_ctz(n);
}

void preComp() {
    for (int i=1; i<MAXN; i++) spf[i] = i;
    for (int i=2; i*i<MAXN; i++) {
        if (spf[i] == i) {
            for (int j=i*i; j<MAXN; j+=i) if (spf[j] == j) spf[j]=i; 
        }
    }

    G[1]=0;
    for (int i=3; i<MAXN; i+=2) {
        int p=spf[i], m=i/p;
        if (m%p==0) G[i]=G[m];
        else G[i] = G[m]+cntTrailZeros(p-1);
    }

    int distCnt = 0;
    for (int n=1; n<MAXN; n++) {
        int s=cntTrailZeros(n);
        int m = n>>s;
        int val = (1<<s)-s+G[m];

        if (!seen[val]) {distCnt++; seen[val]=true;}
        ans[n] = distCnt;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preComp();
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << "\n";
    }
}