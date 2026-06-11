#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n); for (int i=0; i<2*n; i++) cin >> a[i];
        vector<int> p; unordered_set<int> s;
        for (int x: a) {
            if (s.find(x) == s.end()) {
                s.insert(x);
                p.push_back(x);
            }
        }

        for (int i=0; i<n; i++) cout << p[i] << " ";
        cout << "\n";
    }
}