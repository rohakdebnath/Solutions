#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> f (n), vis (n);
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i], ++f[a[i]];
    vector<int> s;

    auto check = [&] (int num, int j) {
        if (j % 2 == 0) return num < s[j - 1];
        return num > s[j - 1];
    };
    for (int i = 0; i < n; ++i) {
        --f[a[i]];
        if (vis[a[i]]) continue;
        while (true) {
            if (!s.empty() and check(a[i], s.size()) and f[s.back()] > 0) {
                vis[s.back()] = 0;
                s.pop_back();
                continue;
            }
            if ((s.size() >= 2) and check(a[i], s.size() - 1) and f[s[s.size() - 1]] * f[s[s.size() - 2]] > 0) {
                vis[s[s.size() - 2]] = vis[s[s.size() - 1]] = 0;
                s.pop_back();
                s.pop_back();
                continue;
            }
            break;
        }
        s.push_back(a[i]);
        vis[a[i]] = 1;
    }
    int m = s.size();
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
        cout << s[i] + 1 << " \n"[i == m - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
