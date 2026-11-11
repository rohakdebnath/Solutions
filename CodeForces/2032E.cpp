#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n);
    int x; cin >> x;
    // do [-1, -1] at x + 1, x + 3, ... x - 2.
    // for doing [-1, -1] operation at i, do 1 at i + 2, i + 4, ... i - 1

    auto sub = [&] (int i) {
        // do [-1, -1] operation at index i
        for (int j = 0; j < n / 2; ++j) {
            ++a[(i + 2 * j + 2) % n];
        }        
    };
    for (int i = 0; i < n / 2; ++i) {
        sub((x + 2 * i + 1) % n);

    }
    for (int i = 0; i < n; ++i) {
        int x = a[(i - 1 + n) % n] + 2 * a[i] + a[(i + 1) % n];
        cout << a[i] << " \n"[i == n - 1];
    }
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
