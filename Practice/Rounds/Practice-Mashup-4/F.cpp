#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, vector<string>> perms;
    vector<string> bases = {"12", "123", "1234"};
    for (const string& b : bases) {
        string s = b;
        do {perms[b].push_back(s);}
        while (next_permutation(s.begin(), s.end()));
    }
    
    int t; cin >> t;
    while(t--){
        string n; int j, k; cin >> n >> j >> k;
        string p1 = perms[n][j-1];
        string p2 = perms[n][k-1];
        int x=0; for (int i=0; i<n.size(); i++) if (p1[i]==p2[i]) x++;
        int y = n.length()-x;
        cout << x << "A" << y << "B\n";
    }
}