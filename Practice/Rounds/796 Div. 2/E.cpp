#include <bits/stdc++.h>
using namespace std;
int ask(const string &s) {cout << "? " << s << endl; int r; cin>>r; return r;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, i, r= 0; cin >> n >> m;
    string s(m, '0'); vector<pair<int, int>> v(m);
    vector<int> sum(m+1);
    for (int i=0; i<m; i++) {
        s[i] = '1';
        v[i] = {ask(s), i};
        s[i] = '0';
    }
    sort(v.begin(), v.end());
    for (int i=0; i<m; i++) {
        s[v[i].second] = '1';
        sum[i+1] = ask(s);
    }
    for (int i=0; i<m; i++) r += (sum[i+1] == sum[i]+v[i].first)*v[i].first;
    cout << "! " << r << endl;

}