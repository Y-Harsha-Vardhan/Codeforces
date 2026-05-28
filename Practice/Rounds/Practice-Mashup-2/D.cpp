#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> delCnt(n, 0), monoStack;
        for (int i=0; i<n; i++) {
            while (!monoStack.empty() && a[monoStack.back()] < a[i]) monoStack.pop_back();
            monoStack.push_back(i);
            delCnt[i] += (i+1) - monoStack.size();
        }

        monoStack.clear();
        for (int i=n-1; i>=0; i--) {
            while (!monoStack.empty() && a[monoStack.back()] < a[i]) monoStack.pop_back();
            monoStack.push_back(i);
            delCnt[i] += (n-i) - monoStack.size();
        }

        int minDel = n; for (int i=0; i<n; i++) minDel = min(minDel, delCnt[i]);
        cout << minDel << "\n";
    }
}