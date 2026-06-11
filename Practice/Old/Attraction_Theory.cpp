#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

struct mint {
    int x;
    mint() : x(0) {}
    mint(long long xx) { x = xx % MOD; if(x < 0) x += MOD; }
    mint operator+(const mint &b) const { return mint(x + b.x); }
    mint operator-(const mint &b) const { return mint(x - b.x); }
    mint operator*(const mint &b) const { return mint(x * b.x); }
    mint operator/(const mint &b) const { return *this * b.inv(); }
    mint& operator+=(const mint &b) { x += b.x; if(x>=MOD) x-=MOD; return *this; }
    mint power(long long n) const { mint res=1, a=*this; while(n){ if(n&1) res = res*a; a = a*a; n>>=1;} return res; }
    mint inv() const { return power(MOD-2); }
    friend ostream& operator<<(ostream &os, const mint &m) { os<<m.x; return os; }
};

struct factorials {
    vector<mint> ff, iff;
    factorials(int n) {
        ff.resize(n+1); iff.resize(n+1);
        ff[0]=1; for(int i=1;i<=n;i++) ff[i]=ff[i-1]*i;
        iff[n]=ff[n].inv();
        for(int i=n-1;i>=0;i--) iff[i]=iff[i+1]*(i+1);
    }
    mint C(int n,int r){
        if(r<0||r>n) return 0;
        return ff[n]*iff[r]*iff[n-r];
    }
    mint solutions(int n,int r){ return C(n+r-1, n-1); }
};

const int PRECOMP = 3e6+69;
factorials F(PRECOMP);

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n+1);
        for (int i=1; i<=n; i++) cin >> a[i];

        mint ans = 0;
        for (int i=1; i<=n; i++) ans += a[i]*n;

        vector<mint> p(n+1), pp(n+1);
        for (int i=1; i<=n; i++) p[i] = p[i-1] + a[i];
        for (int i=1; i<=n; i++) pp[i] = pp[i-1] + p[i];

        for (int k=2; k<=n; k++) {
            for (int x: {1, 2}) {
                for (int y: {1, 2}) {
                    int s = n-x-y-(k-2);
                    if (s<0 || s%2==1) continue;
                    s /= 2;
                    mint avg = mint(2) * (mint(s)/k) + 1;
                    mint ways = F.solutions(k, s);
                    mint sum = pp[n]-pp[k-1]-pp[n-k];
                    ans += sum*avg*ways;

                    if (x==2) ans += p[n-k+1]*ways;
                    if (y==2) ans += (p[n]-p[k-1])*ways;
                }
            }
        }

        cout << ans << "\n";
    }
}