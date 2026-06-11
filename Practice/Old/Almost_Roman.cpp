#include <bits/stdc++.h>
using namespace std;

int cost (char c) {
    if (c == 'I') return 1;
    return 5;
}

int eval (string s) {
    int n = s.size(), ans = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'I' && i+1<n && s[i+1]=='V') ans--;
        else ans += cost(s[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        string s; cin >> s;
        int ans = 0;
        for (int i=0; i<n; i++) if (s[i] == 'X') {s[i] = 'V'; ans+=5;}
        
        int inc = 0, same = 0, qCount = 0;
        for (int i=0; i<n; i++) {
            if (s[i] != '?') continue;
            int r = i;
            while (r < n && s[r] == '?') r++;
            int len = r-i;

            if (i > 0 && s[i-1] == 'I') len++;
            if (r < n && s[r] == 'V') {inc--; len++;}
            inc += len/2; same += len%2;
            qCount += (r-i); i = r-1;
        }

        for (int i=0; i<n; i++) if (s[i] == '?') s[i] = 'I';
        ans += eval(s);

        for (int i=0; i<q; i++) {
            int a, b, c; cin >> a >> b >> c;
            int usedV = max(0, min(b, qCount-c));
            int usedX = max(0, qCount-c-b);
            int curr = ans;
            curr += usedV*4 + usedX*9;
            int rep = usedV + usedX;
            curr -= min(inc, rep)*2;
            rep -= (inc + same);
            curr += max(0, rep)*2;
            cout << curr << "\n";
        }
        
    }
}