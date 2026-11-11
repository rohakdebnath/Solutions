#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n), p (n), leaf (n, true); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> adj (n);
    p[0] = -1;
    for (int i = 1; i < n; ++i) {
        int x; cin >> x; --x;
        p[i] = x;
        adj[x].push_back(i);
        leaf[x] = false;
    }
    vector<int> ord;
    auto dfspath = [&] (auto&& self, int v) -> void {
        if (v) ord.push_back(v);
        for (auto u: adj[v]) self(self, u);
    };
    dfspath(dfspath, 0);

    vector<i64> s (n); //s[i] is the demand vector, how much needs to be extracted from the children
    auto check = [&] (i64 m) -> bool{
        if (a[0] >= m) return true;
        s[0] = m - a[0];
        for (int i: ord) {
            if (leaf[i] and s[p[i]] > a[i]) return false;
            s[i] = s[p[i]] + max<i64>(0, s[p[i]] - a[i]);
            if (s[i] > inf) return false; //demand cannot be more than inf, since it cant be extracted from the leaves anyway in that case (max leaf value is inf)
        }
        return true;
    };
    i64 l = a[0], r = a[0];
    while (check(r)) r *= 2;
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// const int inf = 1e9;
// void solve() {
//     int n; cin >> n;
//     vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
//     vector<vector<int>> adj (n);
//     for (int i = 1; i < n; ++i) {
//         int x; cin >> x; --x;
//         adj[x].push_back(i);
//     }
//     auto dfs = [&] (auto&& self, int v) -> i64 {
//         if (adj[v].empty()) return a[v];
//         i64 m = inf;
//         for (int u: adj[v]) {
//             m = min(self(self, u), m);
//         }
//         if (v == 0) return a[0] + m;
//         return (m <= a[v] ? m : (a[v] + m) >> 1);
//     };
//     cout << dfs(dfs, 0) << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int T; cin >> T;
//     while(T--) solve();
//     return 0;
// }
