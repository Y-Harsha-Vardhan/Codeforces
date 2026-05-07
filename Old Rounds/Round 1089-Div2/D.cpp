#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

ll cntMerge(vector<ll>& a, vector<ll>& temp, int l, int m, int r) {
    int i = l, j = m+1, k = l; ll invCnt = 0;
    while (i<= m && j<=r) {
        if (a[i]<= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            invCnt += (m-i+1);
        }
    }
    
    while(i<=m ) temp[k++] = a[i++];
    while(j<= r) temp[k++] = a[j++];
    for (i=l; i<=r; i++) a[i] = temp[i];
    return invCnt; 
}

ll cntInv(vector<ll>& a, vector<ll>& temp, int l, int r) {
    ll invCnt = 0;
    if (l<r) {
        int m = l+(r-l)/2;
        invCnt += cntInv(a, temp, l, m);
        invCnt += cntInv(a, temp, m+1, r);
        invCnt += cntMerge(a, temp, l, m, r);
    }
    return invCnt;
}

ll getInv(vector<ll>& a) {
    if (a.empty()) return 0;
    vector<ll> temp(a.size());
    return cntInv(a, temp, 0, (int)a.size()-1);
}

ll power(ll base, ll exp) {
    ll res=1; base%=MOD;
    while(exp>0) {
        if (exp%2 == 1) res = (res* base)%MOD;
        base = (base*base)% MOD;
        exp/=2;
    }
    return res;
}

ll modInv(ll n) {return power(n, MOD-2);}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        if (n == 1) {cout << "0\n"; continue;}
    
        sort(b.begin(), b.end());
        vector<ll> W(n*n);
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) W[i*n+j] = a[i]*b[j];
        ll invW = getInv(W); ll invA = getInv(a);
        ll P = (invW - (ll)n*invA)%MOD;
        P = (P+MOD)%MOD;
        ll Q = (1LL*n*(n-1))%MOD;
        ll ans = (P*modInv(Q))%MOD;
        cout << ans << "\n";
    }
}