#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g (3, vector<int> (n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    i64 tot = (accumulate(g[0].begin(), g[0].end(), 0LL) - 1) / 3 + 1;
    vector<int> ans (6);
    auto check = [&] (vector<int> p) -> bool { //checks in the order i, j, kth array for contiguous tot
        int x = 0;
        for (int i = 0; i < 3; ++i) {
            ans[2 * p[i]] = x;
            i64 s = 0;
            int j = x;
            while (j < n and s < tot) {
                s += g[p[i]][j];
                ++j;
            }
            if (s < tot) return false;
            x = j;
            ans[2 * p[i] + 1] = x - 1;
        }
        return true;
    };
    vector<int> p (3); iota(p.begin(), p.end(), 0);
    bool fnd = 0;
    do {
        if (check(p)){
            fnd = 1;
            break;
        }
    } while (next_permutation(p.begin(), p.end()));
    if (!fnd) cout << "-1\n";
    else {
        for (int i = 0; i < 6; ++i) {
            cout << ans[i] + 1 << " \n"[i == 5];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
