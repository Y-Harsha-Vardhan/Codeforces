#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];
        int m; cin >> m;    
        vector<string> s(m); for (int i=0; i<m; i++) cin >> s[i];

        for (int j=0; j<m; j++) {
            const string& x = s[j]; map<int, char> map; vector<int> charInt(26, 2e9);
            if (x.length() != n) {cout << "NO\n"; continue;}
            bool pos = true;
            for (int i=0; i<n; i++) {
                char c = x[i]; int ind = c-'a'; int num = a[i]; 
                if (charInt[ind] != 2e9 && charInt[ind] != num) {pos = false; break;}
                if (map.count(num) && map[num] != x[i]) {pos = false; break;}

                map[num] = x[i];
                charInt[ind] = num;
            }

            cout << (pos ? "YES\n" : "NO\n"); 
        }
    }
}