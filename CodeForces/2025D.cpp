#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<i64> dp (m + 1); //dp[j] = max pass you can get till the ith segment with exactly j intelligence
    vector<i64> f (m + 2);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int r; cin >> r;
        if (r == 0) {
            partial_sum(f.begin(), f.end(), f.begin());
            for (int i = 0; i <= p; ++i) {
                dp[i] += f[i];
            }
            ++p;
            for (int i = p; i >= 1; --i) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            f.assign(m + 1, 0);
        } else if (r > 0) {
            //dp[j] += 1 for all p >= i >= r
            if (r > p) continue;
            ++f[r];
            --f[p + 1];
        } else {
            r *= -1;
            //dp[j] += 1 for all 0 <= j <= p - r
            if (r > p) continue;
            ++f[0];
            --f[p - r + 1];
        }
    }
    partial_sum(f.begin(), f.end(), f.begin());
    for (int i = 0; i <= m; ++i) {
        dp[i] += f[i];
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
