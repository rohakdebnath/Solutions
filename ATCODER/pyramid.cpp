#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    int i0 = -1;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] > 0) {
            i0 = i;
        }
    }

    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int H = h[i0] + abs(x[i0] - cx) + abs(y[i0] - cy);
            bool valid = true;

            for (int i = 0; i < n; ++i) {
                if (max(0, H - abs(x[i] - cx) - abs(y[i] - cy)) != h[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                cout << cx << " " << cy << " " << H << '\n';
                return;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
