#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct el{
    int val;
    int ind;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];

        vector<el> st;
        ll curSuffSum = 0, tot = 0;
        for (int i=n-1; i>=0; i--) {
            curSuffSum += n-i;
            while (!st.empty() && st.back().val==a[i]+1) {
                curSuffSum -= n-st.back().ind;
                st.pop_back();
            }

            st.push_back({a[i], i});
            tot += curSuffSum;
        }

        cout << tot << "\n";
    }
}