#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+7;
int m[MAXN], A[MAXN], prime[MAXN], nxt[MAXN]; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int p=2; p<MAXN; p++) {
        if (prime[p]==0) for (int x=p; x<MAXN; x+=p) if (prime[x]==0) prime[x]=p;
        if (prime[p/prime[p]] == prime[p]) nxt[p] = nxt[p/prime[p]];
        else nxt[p] = p/prime[p];
        m[p] = m[nxt[p]]+1;
        A[p] = A[p/prime[p]]+1;
    }
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << m[n]+A[n]-1 << "\n"; 
    }
}