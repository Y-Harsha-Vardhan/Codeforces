#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll safe_lcm(ll a, ll b, ll m) {
    if (a == 0 || b == 0) return m + 1;
    ll g = std::gcd(a, b);
    ll limit = m / (a / g);
    if (b > limit) return m + 1; 
    return (a / g) * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll a, b, c, m; cin >> a >> b >> c >> m;
        ll num1 = m/a, num2 = m/b, num3 = m/c;
        ll num12 = m/safe_lcm(a, b, m), num13 = m/safe_lcm(a, c, m), num23 = m/safe_lcm(b, c, m);
        ll num123 = m/safe_lcm(safe_lcm(a, b, m), c, m);
        ll days[8] = {0};
        days[7] = num123; days[6] = num12-days[7]; days[5] = num13-days[7]; days[3] = num23-days[7];
        days[4] = num1-days[6]-days[5]-days[7]; 
        days[2] = num2-days[6]-days[3]-days[7];
        days[1] = num3-days[5]-days[3]-days[7];
        
        ll ans1 = 0, ans2 = 0, ans3 = 0;
        const int add1[8] = {0, 0, 0, 0, 6, 3, 3, 2}; 
        const int add2[8] = {0, 0, 6, 3, 0, 0, 3, 2}; 
        const int add3[8] = {0, 6, 0, 3, 0, 3, 0, 2}; 
        
        for (int mask=1; mask<8; mask++) {
            ans1 += days[mask]*add1[mask];
            ans2 += days[mask]*add2[mask];
            ans3 += days[mask]*add3[mask];
        }
        cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }
}