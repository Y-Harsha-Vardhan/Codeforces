#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size(); int dir;
        vector<int> pos[26]; for (int i=0; i<n; i++) pos[s[i]-'a'].push_back(i);
        if (s[0] < s[n-1]) dir = 1;
        else dir = -1;

        vector<int> ans;
        for (char c=s[0]; c != s[n-1]+dir; c += dir) for (int ind: pos[c-'a']) ans.push_back(ind);
        int cost = abs(s[0]-s[n-1]);
        
        cout << cost << " " << ans.size() << "\n";
        for (int i=0; i<ans.size(); i++) cout << ans[i]+1 << " ";
        cout << "\n";
    }
}