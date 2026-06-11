#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> cost;
    ll c=3, cnt=1;
    for (int i=0; i<21; i++) {
        cost.push_back(c);
        c = c*3 + cnt;
        cnt *= 3;
    }
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll minK=0, minCost=0;
        int sz=0;

        while (n) {
            minK += n%3;
            minCost += (n%3)*cost[sz];
            n/=3;
            sz++;
        }

        cout << minCost << "\n";
    }
}