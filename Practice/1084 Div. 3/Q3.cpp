#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; string s; cin >> n >> s;

        string newS = "";
        while (1) {
            string newS = "";
            int k = s.length();

            for (int i=0; i<k;) {
                if (i+1 < k && s[i] == s[i+1]) i+=2;
                else {
                    newS += s[i];
                    i++;
                }
            }
            if (newS == s) break;
            s = newS;
        }

        if (s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}