#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int sum(string s) {
    int ans = 0;
    for (auto c: s) ans += c - '0';
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        string S = to_string(x); int ans = 0;
        if (sum(S)<10) ans = 0;
        else {
            int need = sum(S) - 9;
            vector<int> reduce;
            reduce.push_back((S[0]-'0') - 1);
            for (int i=1; i<S.size(); i++) reduce.push_back(S[i]-'0');
            sort(reduce.rbegin(), reduce.rend());

            int mov=0, removed=0;
            for (int x: reduce) {
                removed += x; mov++;
                if (removed>=need) break;
            }
            ans = mov;
        }

        cout << ans << "\n";
    }
}