#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) cin >> b[i];
        vector<int> diff(n), zeroB; set<int> uniqDiff; bool pos = true;
        for (int i=0; i<n; i++) {
            diff[i] = a[i] - b[i];
            if (diff[i] < 0) {pos = false; break;}
            if (b[i] == 0) zeroB.push_back(i);
            else uniqDiff.insert(diff[i]);
        }
        if (!pos) {cout << "NO\n"; continue;}
        if (zeroB.size() == n) {cout << "YES\n"; continue;}
        if (uniqDiff.size() != 1) cout << "NO\n";
        else {
            int x = *uniqDiff.begin(); 
            for (int d : zeroB) if (diff[d] > x) pos = false;

            if (pos) cout << "YES\n";
            else cout << "NO\n";
        }
        
    }
}