#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;
        vector<int> cnt(26, 0);
        bool pos=true;
        for (int i=0; i<n; i++) {
            if (i>=k || i+k<n) {
                cnt[s[i]-'a']++;
                cnt[t[i]-'a']--;
            } else pos &= (s[i] == t[i]);
        }

        cout << (pos && (count(cnt.begin(), cnt.end(), 0)==26) ? "YES\n" : "NO\n");
    }
}