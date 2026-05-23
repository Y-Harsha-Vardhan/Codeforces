#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, int>> paths;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; paths.clear();
        for (int i=0; i<n; i++) {
            ll x; cin >> x;
            ll curr=x; int dist=0;
            while (curr>2) {
                paths.push_back({curr, dist});
                if (curr%2 == 0) curr/=2;
                else curr++;
                dist++;
            }

            if (curr == 1) {paths.push_back({1, dist}); paths.push_back({2, dist+1});}
            else if (curr == 2) {paths.push_back({2, dist}); paths.push_back({1, dist+1});}
        }

        sort(paths.begin(), paths.end());
        ll minDist =-1; int i=0, m=paths.size();
        while (i<m) {
            int j=i; ll currVal = paths[i].first; int currDist = 0;
            int cnt = 0;
            while (j<m && paths[j].first==currVal) {
                currDist += paths[j].second;
                cnt++; j++;
            }
            if (cnt ==n) if (minDist==-1 || currDist< minDist) minDist = currDist;
            i = j;
        }

        cout << minDist << "\n";
    }
}