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

        int l=0, r=1e9+5;
        while (l<r) {
            int mid = (l+r)/2;
            int one = 0, zero=0; int prev=-1;
            for (int i=0; i<n; i++) {
                int type = 0;
                if (a[i]>=mid) type++;
                if (b[i]>=mid) type++;

                if (type==1) continue;
                if (type == 2) {one++; prev = 1;}
                if (type == 0) {
                    if (prev!=0) zero++;
                    prev=0;
                }
            }

            if (one>zero) l = mid+1;
            else r = mid;
        }

        cout << l-1 << "\n";
    }
}