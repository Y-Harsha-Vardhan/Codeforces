#include <bits/stdc++.h>
using namespace std;

int basePrime(int x) {
    set<int> s;
    for (int i=2; i*i<=x; i++) {
        while (x%i == 0) {
            s.insert(i);
            x /= i;
        }
    }

    if (x>1) s.insert(x);
    if (s.size() > 1) return -1;
    if (s.size() == 0) return 1;
    return *s.begin();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b(n); for (int i=0; i<n; i++) b[i] = basePrime(a[i]);

        if (is_sorted(a.begin(), a.end())) {cout << "Bob\n"; continue;}
        else if (*min_element(b.begin(), b.end()) == -1) {cout << "Alice\n"; continue;}
        else if (is_sorted(b.begin(), b.end())) {cout << "Bob\n"; continue;}
        else {cout << "Alice\n"; continue;}
    }
}