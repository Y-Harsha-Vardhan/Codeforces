#include <bits/stdc++.h>
using namespace std;

long long maxSubSum(vector<int> a) {
    long long best = a[0];
    long long curr = a[0];

    for (int i=1; i<a.size(); i++) {
        curr = max<long long>(a[i], curr + a[i]);
        best = max(best, curr);
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int &x : a) cin >> x;
        vector<int> b(n); for (int &x : b) cin >> x;

        
    }
}