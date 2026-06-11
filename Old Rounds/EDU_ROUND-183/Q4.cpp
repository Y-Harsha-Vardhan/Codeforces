#include <bits/stdc++.h>
using namespace std;

const int MAXN = 31;
const int MAX_S = MAXN*(MAXN-1)/2;

bool dp[MAXN][MAX_S];
int parent[MAXN][MAX_S];

void precomp() {
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAX_S; j++) {
            dp[i][j] = false;
            parent[i][j] = 0;
        }
    }

    dp[0][0] = true;

    for (int l=1; l<MAXN; l++) {
        int cost = l*(l-1)/2;
        for (int i=l; i<MAXN; i++) {
            for (int j=cost; j<MAX_S; j++) {
                if (!dp[i][j] && dp[i-l][j-cost]) {
                    dp[i][j] = true;
                    parent[i][j] = l;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precomp();

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        int tot_subseg = n*(n-1)/2;
        int s = tot_subseg - k;

        if (s<0 || !dp[n][s]) {cout << "0\n"; continue;}

        vector<int> runs;
        int curr_n = n;
        int curr_s = s;
        while (curr_n > 0) {
            int l = parent[curr_n][curr_s];
            if (l <= 0) break;
            runs.push_back(l);
            curr_n -= l;
            curr_s -= l*(l-1)/2;
        }

        vector<int> p;
        int curr_num = n;
        for (int l : runs) {
            int start_num = curr_num-l+1;
            for (int i=start_num; i<=curr_num; i++) p.push_back(i);
            curr_num -= l;
        }

        for (int i=0; i<n; i++) cout << p[i] << (i == n-1 ? "" : " ");
        cout << "\n";
    }
}