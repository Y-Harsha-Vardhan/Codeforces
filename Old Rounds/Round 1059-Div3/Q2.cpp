#include <bits/stdc++.h>
using namespace std;

bool isPalind(const string& s) {
    string reversed_S = s;
    reverse(reversed_S.begin(), reversed_S.end());
    return (s == reversed_S);
}

bool isNonDec(const string& s) {
    for (int i=0; i<s.length()-1; i++) {
        if (s[i] > s[i+1]) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for (int i = (1 << n) - 1; i >= 0; i--) {
        string p = "", x = "";
        vector<int> p_IND;
        
        for (int j=0; j<n; j++) {
            if ((i>>j)&1) { p+=s[j]; p_IND.push_back(j+1);}
            else x+=s[j]; 
        }

        if (isNonDec(p) && isPalind(x)) {
            cout << p_IND.size() << endl; 
            for (int k=0; k<p.size(); k++) {
                cout << p_IND[k] << (k == p_IND.size()-1 ? "" : " ");
            } 
            cout << endl; return;
        }
    }

    cout << "-1" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}