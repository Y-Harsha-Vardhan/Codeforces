#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        ll a; int n; cin >> a >> n;
        vector<int> d(n); for (int i=0; i<n; i++) cin >> d[i];
        string S = to_string(a); int L = S.length();
        
        ll minDiff = -1, bestB=-1;
        auto update = [&](const string& candStr) {
            if (candStr.empty()) return;
            ll cand = stoll(candStr);
            ll diff = abs(a-cand);
            if (minDiff==-1 || diff<minDiff) {minDiff=diff; bestB=cand;}
        };

        // Case-1: a=b
        bool exact=true;
        for (char c: S) {
            int x = c-'0';
            if (find(d.begin(), d.end(), x) == d.end()) {exact=false; break;}
        }
        if (exact) {cout << 0 << "\n"; continue;}

        // Case-2: b>a
        // I - same length
        for (int i=L-1; i>=0; i--) {
            bool prefixValid = true;
            for (int j=0; j<i; j++) {
                if (find(d.begin(), d.end(), S[j]-'0') == d.end()) {prefixValid=false; break;}
            }
            if (!prefixValid) continue;

            int currDigit = S[i]-'0';
            int nxtDig = -1;
            for (int x: d) if (x>currDigit) {nxtDig=x; break;}
            if (nxtDig != -1) {
                string cand = S.substr(0, i) + to_string(nxtDig);
                while (cand.length()<L) cand += to_string(d.front());
                update(cand);
            }
        }

        // II - length L+1
        int firstNonZero=-1;
        for (int x: d) if (x>0) {firstNonZero=x; break;}
        if (firstNonZero != -1) {
            string cand = to_string(firstNonZero);
            while (cand.length() < L+1) cand += to_string(d.front());
            update(cand);
        }
        else if (d.size()==1 && d[0]==0) update("0");

        // Case-3: b<a
        for (int i=L-1; i>=0; i--) {
            bool prefixValid = true;
            for (int j=0; j<i; j++) {
                if (find(d.begin(), d.end(), S[j]-'0') == d.end()) {prefixValid=false; break;}
            }
            if (!prefixValid) continue;

            int currDigit = S[i]-'0';
            int prevDig = -1;
            for (int j=n-1; j>=0; j--) if (d[j]<currDigit) {prevDig=d[j]; break;}
            if (prevDig != -1) {
                if (i==0 && prevDig==0 && L>1) continue;
                string cand = S.substr(0, i) + to_string(prevDig);
                while (cand.length()<L) cand += to_string(d.back());
                update(cand);
            }
        }

        if (L>1) {
            string cand = "";
            while (cand.length() < L-1) cand += to_string(d.back());
            update(cand);
        }
        else {
            if (find(d.begin(), d.end(), 0) != d.end()) update("0");
        }

        cout << minDiff << "\n";
    }
}