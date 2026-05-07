#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primes;
void genPrimes() {
    const int LIMIT = 200000;
    vector<bool> prime(LIMIT + 1, true);

    prime[0] = prime[1] = false;

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= LIMIT; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                prime[j] = false;
            }
        }
    }

    // Store first 5000 primes
    for (int i = 2; i <= LIMIT; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    genPrimes();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) a[i] = primes[i]*primes[i+1];
        for (ll x : a) cout << x << " ";
        cout << "\n";
    }
}