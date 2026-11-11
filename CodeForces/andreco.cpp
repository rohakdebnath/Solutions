// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// void solve() {
//     int n; cin >> n;
//     vector<int> a (n - 1); for (int i = 0; i < n - 1; ++i) cin >> a[i];
//     vector<int> ans = {a[0]};
//     for (int i = 1; i < n - 1; ++i) {
//         ans.push_back(a[i - 1] | a[i]);
//     }
//     ans.push_back(a[n - 2]);

//     vector<int> re;
//     for (int i = 1; i < n; ++i) {
//         re.push_back(ans[i] & ans[i - 1]);
//     }
//     if (re == a) {
//         for (int i = 0; i < n; ++i) {
//             cout << ans[i] << " \n"[i == n - 1];
//         }
//     } else {
//         cout << "-1\n";
//     }

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
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int m = 0;
    for (int i = 0; i < n; i += 2) {
        m = max(m, a[i]);
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
