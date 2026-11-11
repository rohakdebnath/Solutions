//function: f[i] = starting with ith potata, the index of the first potata j which exceeds the box size X. f transforms it's index to another
//we can double this operator to find the index of the potata after filling two boxes by applying the operator twice to obtain f_2, which is an operator which takes in an index, then returns the index after two successive applications of f_1, similarly f_(1 << n) can be found

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, q, x, s = 0; cin >> n >> q >> x;
    vector<i64> w (n); for (int i = 0; i < n; ++i) cin >> w[i], s += w[i];
    vector<i64> p = w;
    p.insert(p.end(), w.begin(), w.end());
    partial_sum(p.begin(), p.end(), p.begin());
    vector<i64> c (n); //c[i] = number of potatas on a box if we start from the ith potata
    for (int i = 0; i < n; ++i) {
        c[i] = x / s * n;
        i64 y = x % s;
        i64 start = i - 1 >= 0 ? p[i - 1]: 0;
        c[i] += lower_bound(p.begin(), p.end(), start + y) - p.begin() - i + 1;
    }

    vector<vector<i64>> dp (41, vector<i64> (n)); //dp[i][j] = after (1 << i) moves, the transformation of j

    for (int i = 0; i < n; ++i) dp[0][i] = (i + c[i]) % n;
    for (int i = 1; i < 41; ++i) {
        for (i64 j = 0; j < n; ++j) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    while (q--) {
        i64 k; cin >> k; k--;
        i64 j = 0;
        for (int i = 0; i < 41; ++i) {
            if (((1LL << i) & k) == 0) continue;
            j = dp[i][j];
        }
        cout << c[j] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
