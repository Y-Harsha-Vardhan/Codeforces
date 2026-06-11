#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int M=0; vector<ll> h(n);
        for (int i=0; i<n; i++) {
            cin >> h[i];
            if (h[i]>h[M]) M=i;
        }
        vector<ll> cwSum(n,0), ccwSum(n, 0);
        // clock-wise
        vector<pair<ll, int>> cwSt; ll currCW = 0;
        for (int k=1; k<n; k++) {
            int i=(M-k+n)%n, cnt=1;
            while (!cwSt.empty() && cwSt.back().first<=h[i]) {
                currCW -= cwSt.back().first * cwSt.back().second;
                cnt += cwSt.back().second;
                cwSt.pop_back();
            }
            cwSt.push_back({h[i], cnt});
            currCW += h[i]*cnt;
            cwSum[i] = currCW;
        }
        // counter-clock-wise
        vector<pair<ll, int>> ccwSt; ll currCCW = 0;
        for (int k=1; k<n; k++) {
            int p=(M+k)%n, cnt=1;
            while (!ccwSt.empty() && ccwSt.back().first<=h[p]) {
                currCCW -= ccwSt.back().first * ccwSt.back().second;
                cnt += ccwSt.back().second;
                ccwSt.pop_back();
            }
            ccwSt.push_back({h[p], cnt});
            currCCW += h[p]*cnt;
            ccwSum[(p+1)%n] = currCCW;
        }

        for (int i=0; i<n; i++) cout << cwSum[i] + ccwSum[i] << " ";
        cout << "\n";
    }
}