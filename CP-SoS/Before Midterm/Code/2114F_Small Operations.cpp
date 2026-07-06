#include <bits/stdc++.h>
using namespace std;

vector<long long> get_divisors(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

long long largestPrimeFactor(long long n) {
    long long maxPrime = -1;
    while (n % 2 == 0) n /= 2, maxPrime = 2;
    for (long long i = 3; i * i <= n; i += 2)
        while (n % i == 0) n /= i, maxPrime = i;
    if (n > 2) maxPrime = n;
    return maxPrime;
}

int calc(int n, int k){
    if (n==1) return 0;
    if (largestPrimeFactor(n) > k) return -1;

    vector<long long> divisors = get_divisors(n);
    unordered_map<long long, int> dist;
    for (auto d : divisors) dist[d] = -1;

    queue<long long> q;
    dist[1] = 0;
    q.push(1);

    while(!q.empty()){
        long long curr = q.front();
        q.pop();

        if (curr == n) return dist[n];

        for (auto next : divisors) {
            if (next <= curr) continue;
            if (next % curr != 0) continue;

            long long factor = next/curr;
            if (factor <= k && dist[next] == -1){
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

void solve(int x, int y, int k){
    if (x==y) {cout << "0\n"; return;}
    int g = gcd(x,y);

    int X = calc(x/g, k);
    int Y = calc(y/g, k);

    if (X==-1 || Y==-1) {cout << "-1\n"; return;}
    cout << X + Y << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        solve(x,y,k);
    }
}