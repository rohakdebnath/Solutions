#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<vector<int>> g (n, vector<int> (m));
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            v.push_back(g[i][j] % d);
        }
    }
    for (auto it = v.begin() + 1; it < v.end(); ++it) {
        if (*it != *(it - 1)) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i][j] -= v[0];
        }
    }
    auto check = [&] (int mid) {
        vector<int> mov (2);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    mov[i] += abs(g[j][k] - (mid + i) * d) / d;
                }
            }
        }
        return mov;
    };

    int l = 0, r = 1;
    while (check(r)[0] >= check(r)[1]) r *= 2;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        auto x = check(mid);
        if (x[0] >= x[1]) l = mid;
        else r = mid;
    }
    cout << check(r)[0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
