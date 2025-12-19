#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int &x : a) cin >> x;
        unordered_set<int> st(a.begin(), a.end());
        int uniqCount = st.size();

        sort(a.begin(), a.end());
        int i;
        for (i=0; i<n; i++) {
            if (a[i] >= uniqCount) break;
        }
        cout << a[i] << "\n";
    }
}