#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

ll power(int exp) {
    ll res = 1;
    for (int i=0; i<exp; i++) res *= 10;
    return res;
}

ll get_sum(ll n) {
    if (n <= 0) return 0;
    if (n < 10) return n * (n + 1) / 2;
    
    ll p = 1, log_p = 0;
    while (n / (p * 10) > 0) {
        p *= 10; 
        log_p++;
    }
    
    ll d = n / p, r = n % p;
    ll sum_blocks = d * log_p * 45 * (p / 10);
    ll sum_first_digits = (d * (d - 1) / 2) * p;
    ll sum_remaining_first = d * (r + 1);
    
    return sum_blocks + sum_first_digits + sum_remaining_first + get_sum(r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> fact; ll x = 9;
    for (int i=0; i<15; i++) {
        fact.push_back(x);
        x *= 10;
    } 
    
    int t; cin >> t;
    while(t--){
        ll k; cin >> k; // 9, 90, 900, ...
        ll temp = k; ll dig = 1;
        while (1) {
            temp -= dig * fact[dig-1];
            if (temp < 0) break;
            dig++;
        }

        temp += dig * fact[dig-1]; temp--;
        ll a = temp/dig, r = temp%dig;
        ll last_full = power(dig-1)-1+a;
        ll next_num = last_full+1;

        ll ans = get_sum(last_full);
        string s = to_string(next_num);
        for (int i=0; i<=r; i++) ans += s[i]-'0';
        cout << ans << "\n";
    }
}