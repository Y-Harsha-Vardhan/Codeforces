#include <bits/stdc++.h>
using namespace std;

void bubSort(vector<int>& a, vector<pair<int, int>>& op, int ind) {
    int n = a.size();
    bool swapped = false;
    for (int i=0; i<n-1; i++) {
        swapped = false;
        for (int j=0; j<n-1-i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swapped = true;
                op.push_back({ind, j+1});
            }
        }
        if (!swapped) break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        vector<pair<int, int>> op;
        bubSort(a, op, 1); 
        bubSort(b, op, 2);

        for (int i=0; i<n; i++) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
                op.push_back({3, i+1});
            }
        }
        int k = op.size();
        cout << k << "\n";
        for (int i=0; i<k; i++) {
            cout << op[i].first << " " << op[i].second << "\n";
        }
    }
}