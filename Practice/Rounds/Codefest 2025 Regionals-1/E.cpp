#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, b;
        cin >> n >> b;

        if (b != 4) {
            if (n % 2 == 1) {
                if (n == 1) {
                    if (b == 3) {
                        cout << "NO\n";
                    } else {
                        cout << "YES\n";
                        cout << "1\n";
                        cout << "1 3 1\n";
                    }
                } else {
                    cout << "YES\n";
                    cout << n / 2 << "\n";
                    cout << "3 4 1 2 3\n";

                    for (int i = 4; i <= n; i += 2) {
                        cout << "2 4 " << i << " " << i + 1 << "\n";
                    }
                }
            } else {
                cout << "YES\n";
                cout << n / 2 << "\n";

                for (int i = 1; i <= n; i += 2) {
                    cout << "2 4 " << i << " " << i + 1 << "\n";
                }
            }
        } 
        else {
            cout << "YES\n";

            if (n % 4 == 0) {
                cout << n / 4 << "\n";
                for (int i = 1; i <= n; i += 4) {
                    if (i % 3)
                        cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                    else
                        cout << "4 6 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                }
            }
            else if (n % 4 == 1) {
                cout << ((n - 1) / 4) + 1 << "\n";
                cout << "1 3 1\n";

                for (int i = 2; i <= n; i += 4) {
                    if (i % 3)
                        cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                    else
                        cout << "4 6 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                }
            }
            else if (n % 4 == 2) {
                cout << ((n - 2) / 4) + 2 << "\n";
                cout << "1 3 1\n";
                cout << "1 1 2\n";

                for (int i = 3; i <= n; i += 4) {
                    if (i % 3)
                        cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                    else
                        cout << "4 6 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                }
            }
            else {
                cout << ((n - 3) / 4) + 3 << "\n";
                cout << "1 3 1\n";
                cout << "1 1 2\n";
                cout << "1 2 3\n";

                for (int i = 4; i <= n; i += 4) {
                    if (i % 3)
                        cout << "4 2 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                    else
                        cout << "4 6 " << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                }
            }
        }
    }
}
