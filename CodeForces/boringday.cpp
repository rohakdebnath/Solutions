// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// void solve() {
//     int n, l, r; cin >> n >> l >> r;
//     vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
//     i64 ans = 0, s = 0;
//     int j = 0;
//     for (int i = 0; i < n;) {
//         while (j < n and s < l) {
//             s += a[j++];
//         }
//         if (s <= r and s >= l) {
//             ++ans;
//             i = j;
//             s = 0;
//         } else {
//             s -= a[i++];
//         }
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int T; cin >> T;
//     while(T--) solve();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n + 1); //d[i] = max valid segments till length i 
    i64 s = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (j < i){
            j = i;
            s = 0;
        }
        while (j < n and s < l){
            s += a[j++];
        }
        if (s <= r and s >= l){
            dp[j] = max(dp[j], dp[i] + 1);
        }
        s -= a[i];
    }
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

