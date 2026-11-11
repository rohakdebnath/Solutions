#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmax(i64& a, i64 b) {
    a = max(a, b);
}
const i64 inf = 1e14;
void solve() {
    i64 n, q; cin >> n >> q;
    vector<i64> v (n); for (i64 i = 0; i < n; ++i) cin >> v[i];
    vector<i64> c (n); for (i64 i = 0; i < n; ++i) cin >> c[i], --c[i];

    while (q--) {
        i64 a, b; cin >> a >> b;
        vector<i64> dp (n, -inf); //dp[i] = maximum pts from a subsequence ending with color i
        //it is always optimal to pick the maximum pts subsequence to continue because b * v[i] is independent of what the end is, it just shouldnt match, in case of matching color, we have to update with a * v[i]
        vector<i64> m (2, 0);
        for (i64 i = 0; i < n; ++i) {
            if (dp[c[i]] == m[1]) { //means the max dp element corresponds to c[i] only, any increase in dp[c[i]] should reflect on m[1] as well as m[1] represents color c[i]
                chmax(dp[c[i]], m[1] + a * v[i]);
                chmax(dp[c[i]], m[0] + b * v[i]);
                chmax(m[1], dp[c[i]]);
            } else { //c[i] is definitely not m[1] (not guaranteed to correspond to m[0] either), however, any change in dp[c[i]] (which corresponds to color c[i]) has to be given a chance to climb up the ladders, we this redefine our m to be the top 2 amongst m[0], m[1] and dp[c[i]]
                chmax(dp[c[i]], dp[c[i]] + a * v[i]);
                chmax(dp[c[i]], m[1] + b * v[i]);
                chmax(m[0], dp[c[i]]);
                sort(m.begin(), m.end());
            }
        }
        cout << m[1] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

// 2 3 4 5 5 
// m = {5, 5}
//current color is 4, dp[i] = 5. 
