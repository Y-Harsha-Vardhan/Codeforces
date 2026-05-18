#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> pts(n);
        vector<vector<int>> buckets(n+1);
        vector<int> hasY(n+1, 0);

        for (int i=0; i<n; i++) {
            cin >> pts[i].first >> pts[i].second;
            buckets[pts[i].first].push_back(pts[i].second);
            hasY[pts[i].second] = 1;
        }

        vector<pair<int, int>> sortedPts; sortedPts.reserve(n);
        for (int x=1; x<=n; x++) for (int y: buckets[x]) sortedPts.push_back({x, y});

        vector<int> prefMin(n), prefMax(n);
        prefMin[0] = sortedPts[0].second;
        prefMax[0] = sortedPts[0].second;
        for (int i=1; i<n; i++) {
            prefMin[i] = min(sortedPts[i].second, prefMin[i-1]);
            prefMax[i] = max(sortedPts[i].second, prefMax[i-1]);
        }

        vector<int> suffMin(n), suffMax(n);
        suffMin[n-1] = sortedPts[n-1].second;
        suffMax[n-1] = sortedPts[n-1].second;
        for (int i=n-2; i>=0; i--) {
            suffMin[i] = min(suffMin[i+1], sortedPts[i].second);
            suffMax[i] = max(suffMax[i+1], sortedPts[i].second);
        }

        vector<int> prefUniqY(n+1, 0);
        for (int y=1; y<=n; y++) prefUniqY[y] = prefUniqY[y-1] + hasY[y];
        ll distinctColorings = 0;

        for (int i=0; i<n-1; i++) {
            if (sortedPts[i].first != sortedPts[i+1].first) {
                int Ymin = max(prefMin[i], suffMin[i+1]);
                int Ymax = min(prefMax[i], suffMax[i+1]);
                if (Ymin<Ymax) distinctColorings += prefUniqY[Ymax-1] - prefUniqY[Ymin-1];
            }
        }

        cout << distinctColorings << "\n";
    }
}