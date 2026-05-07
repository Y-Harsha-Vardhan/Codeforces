#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; ll x, y; cin >> n >> x >> y;
        string s; cin >> s;

        vector<int> blk;
        int curBlkSum = 0;
        int curSign = 1;

        bool firstBlk = true;
        int c0 = 0;
        for (int i=0; i<n; i++) {
            char c = s[i];
            if (c == '?') {
                if (firstBlk) {
                    c0 = curBlkSum;
                    firstBlk = false;
                }
                else blk.push_back(abs(curBlkSum));
                curBlkSum = 1;
                curSign = 1;
            }
            else {
                int trans = (c=='0' ? 1 : -1);
                curSign *= trans;

                if (curBlkSum==0 && i==0) curBlkSum=0;
                curBlkSum += curSign;
            }
        }
        
        blk.clear(); c0 = 0;
        int segSum=0, segSign=1;
        int i=0, curY=1;
        while (i<n && s[i]!='?') {
            int tr = (s[i]=='0' ? 1:-1);
            curY *= tr;
            c0+= curY;
            i++;
        }

        while (i<n) {
            i++;
            int blkVal =1, curr=1;
            while (i<n && s[i]!='?') {
                int tr = (s[i]=='0' ? 1:-1);
                curr *= tr;
                blkVal += curr;
                i++;
            }
            blk.push_back(abs(blkVal));
        }

        const int OFFSET = 100002;
        static bitset<200005> bs;
        bs.reset(); bs[OFFSET+c0]=1;
        for (int v : blk) {
            if (v==0) continue;
            bs = (bs << v) | (bs >> v);
        }
        
        vector<ll> coolVals;
        for (int k=bs._Find_first(); k<bs.size(); k=bs._Find_next(k)) {
            ll Y = k-OFFSET;
            ll t1=x*Y*Y, t2=(x-y)*Y, t3=n*y;
            ll val = t1+t2+t3;
            coolVals.push_back(val/2); 
        }
        sort(coolVals.begin(), coolVals.end());
        coolVals.erase(unique(coolVals.begin(), coolVals.end()), coolVals.end());
        
        ll totSum = 0;
        for (ll v: coolVals) totSum = (totSum+(v%MOD))%MOD;
        if (totSum<0) totSum+=MOD;

        cout << totSum << "\n";
    }
}