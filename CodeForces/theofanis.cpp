// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// void solve() {
//     i64 n; cin >> n;
//     vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
//     vector<i64> p (n); partial_sum(a.rbegin(), a.rend(), p.rbegin());
//     cout << accumulate(a.begin(), a.end(), 0LL) + (accumulate(p.begin() + 1, p.end(), 0LL, [&] (i64 s, i64 i) {return s + max(i, 0LL);})) << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     i64 T; cin >> T;
//     while(T--) solve();
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
        return;
    }
    cout << (k > 1 ? "YES\n": "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
