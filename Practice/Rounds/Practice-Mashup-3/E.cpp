#include <bits/stdc++.h>
using namespace std;

int n; int cnt[10];

bool can(int k) {
    for (int x = 0; x <= min(k, cnt[1] / 2); x++) {
        int zeros = cnt[0];
        if (zeros < k - x) continue;
        int firstDigit = zeros + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] - 2 * x;
        if (firstDigit - (k - x) < k) continue;
        int remaining = firstDigit + cnt[6] + cnt[7] + cnt[8] + cnt[9];
        if (remaining - (k - x) - k < 2 * k - x) continue;

        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        fill(cnt, cnt + 10, 0);
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            cnt[c - '0']++;
        }
        int lo = 0, hi = n / 4 + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (can(mid)) lo = mid;
            else hi = mid;
        }
    
        cout << lo << '\n';
    }
}