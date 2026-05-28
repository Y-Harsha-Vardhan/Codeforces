#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <unistd.h>
using namespace std;

const int maxVal = 1e6 + 10;
vector<int> vis(maxVal, 0);
void readArr(vector<int>& currArr, int sz) {
    currArr.resize(sz);
    for (int &val : currArr) {
        cin >> val;
        vis[val] = 0;
    }

    reverse(currArr.begin(), currArr.end());
    vector<int> uniq; 
    for (int val: currArr) {
        if (!vis[val]) {
            uniq.push_back(val);
            vis[val] = 1;
        }
    }

    for (int val: uniq) vis[val] = 0;
    currArr = uniq;
}

void removeVis(vector<int>& currArr) {
    if (currArr.size() == 1 && currArr[0] == INT_MAX) return;
    vector<int> filtArr;
    for (int val: currArr) if (!vis[val]) filtArr.push_back(val);
    currArr = filtArr;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> arr(n+1);
        vector<bool> isProcessed(n+1, false);

        for (int i=1; i<=n; i++) {
            int sz; cin >> sz;
            readArr(arr[i], sz);
        }

        for (int step=1; step<=n; step++) {
            int best = -1;
            for (int i=1; i<=n; i++) {
                if (!isProcessed[i]) {
                    if (best==-1 || arr[i]<arr[best]) best = i;
                }
            }

            for (int val: arr[best]) {
                cout << val << " ";
                vis[val] = 1;
            }

            arr[best] = {INT_MAX}; isProcessed[best] = true;
            for (int i=1; i<=n; i++) if (!isProcessed[i]) removeVis(arr[i]);
        }

        cout << "\n";
    }
}