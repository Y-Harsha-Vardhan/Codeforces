#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get(vector<int>& a) {
    if (a.empty()) return 0;
    int pos = (int)a.size()/2; ll val=0;
    for (int i=0; i<a.size(); i++) val += abs(a[pos]-a[i]) - abs(pos-i);
    return val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s; vector<int> a, b;
        for (int i=0; i<n; i++) {
            char c = s[i];
            if (c == 'a') a.push_back(i+1);
            else b.push_back(i+1);
        }
        cout << min(get(a), get(b)) << "\n";
    }
}