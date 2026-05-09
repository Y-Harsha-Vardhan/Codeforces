#include <bits/stdc++.h>
using namespace std;

bool check(int k, const vector<int> &a) {
    vector<int> freq(k, 0);
    vector<int> remElem;
    for (int x: a) {
        if (x<k) freq[x]++;
        else remElem.push_back(x);
    }

    vector<int> remTarg;
    for (int i=0; i<k; i++) {
        if (freq[i]>0) {
          freq[i]--;
          while (freq[i] >0) {
              remElem.push_back(i);
              freq[i]--;
          }
        } 
        else remTarg.push_back(i);
    }

    sort(remElem.begin(), remElem.end());
    int j=0; 
    for (int i=0; i<remTarg.size(); i++) {
        int req = 2*remTarg[i]+1;
        while(j<remElem.size() && remElem[j]<req) j++;
        if (j == remElem.size()) return false;
        j++;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        int l=0, h=n, ans=0;
        while (l<=h) {
            int m = l + (h-l)/2;
            if (check(m, a)) {
                ans = m;
                l = m+1;
            }
            else h = m-1;
        }
        cout << ans << "\n";
    }
}