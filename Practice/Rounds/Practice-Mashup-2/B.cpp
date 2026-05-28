#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeBases(int n) {
    vector<int> bases;
    if (n%2 == 0) {
        bases.push_back(2);
        while (n%2 == 0) n/=2;
    }

    for (int i=3; i*i<=n; i+=2) {
        if (n%i == 0) {
            bases.push_back(i);
            while (n%i == 0) n/=i;
        } 
    }

    if (n>2) bases.push_back(n);
    return bases;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> primeFactors = getPrimeBases(n);
        int k = 1; for (int x: primeFactors) k = k*x;
        cout << k << "\n";
    }
}