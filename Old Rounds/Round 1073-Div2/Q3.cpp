#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string t = s; sort(t.begin(), t.end());

        if (s == t) {cout << "Bob\n"; continue;}
        vector<int> moves;
        for (int i=0; i<n; i++) if (s[i] != t[i]) moves.push_back(i+1);
        cout << "Alice\n";
        cout << moves.size() << "\n";
        for (int x : moves) cout << x << " ";
        cout << "\n";
    }
}