#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n){
    if (n==0 || n==1) return false;
    if (n==2 || n==3) return true;
    int a = static_cast<int>(sqrt(n));
    for (int i=2; i<=a; i++){
        if (n%i==0) return false;
    }
    return true;
}

void solve(ll n, int k){
    if (n==1) {
        if (k==2) {cout << "YES\n"; return;}
        else {cout << "NO\n"; return;}
    }

    if (k==1) {
        if(isPrime(n)) {cout << "YES\n"; return;}
        else {cout << "NO\n"; return;}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll n; int k;
        cin >> n >> k;
        if ((n%2==0 && n!=2) || (n>1 && k>1)) cout << "NO\n";
        else solve(n,k);
    }
}