#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int tot_a = 0, tot_b = 0;
        for (char x : s) {
            if (x == 'a') tot_a++;
            else tot_b++;
        }

        if (tot_a == tot_b) {cout << "0\n"; continue;}

        int diff = tot_a - tot_b;
        int min_l = n + 1;

        map<int, int> last_occ;
        last_occ[0] = 0;

        int curr_bal = 0;
        for (int i=1; i<=n; i++) {
            if (s[i-1] == 'a') curr_bal++;
            else curr_bal--;

            int targ_bal = curr_bal - diff;
            if (last_occ.count(targ_bal)) {
                int l = last_occ[targ_bal];
                min_l = min(min_l, i-l);
            }
            last_occ[curr_bal] = i;
        }

        if (min_l >= n) cout << "-1\n";
        else cout << min_l << "\n"; 
    }
}