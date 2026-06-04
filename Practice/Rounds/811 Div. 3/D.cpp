#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q; cin >> q;
    while(q--){
        string t; cin >> t;
        int n; cin >> n;
        vector<string> s(n); for (int i=0; i<n; i++) cin >> s[i];
        vector<pair<int, int>> ans; int L=0, R=0; bool pos = true;
        while (R < t.size()) {
            int bestR=-1, bestId=-1, bestPos=-1;
            for (int pos=L; pos<=R; pos++) {
                for (int id=0; id<n; id++) {
                    int len = s[id].size();
                    if (pos+len>t.size()) continue;
                    if (t.substr(pos, len) == s[id]) {
                        if (pos+len > bestR) {
                            bestR = pos+len;
                            bestId=id;
                            bestPos = pos;
                        }
                    }
                }
            }

            if (bestR == -1) {pos = false;}
            ans.push_back({bestId+1, bestPos+1});
            L = max(bestPos+1, R+1);
            R = bestR;
        }

        if (!pos) {cout << "-1\n"; continue;}
        cout << ans.size() << "\n";
        for (auto &[id, pos]: ans) cout << id << " " << pos << "\n";
    }
}