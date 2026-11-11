#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> g;
    for (int i = n - 1; i >= n / 2; --i) {
        g.push_back(a[i]);
        a.pop_back();
    }
    reverse(a.begin(), a.end());

    vector<int> ans;
    while (g.size()) {
        ans.push_back(g.back()); g.pop_back();
        if (a.size()) ans.push_back(a.back()), a.pop_back();
    }
    int c = 0;
    for (int i = 1; i < n - 1; ++i) {
        c += ((ans[i] < ans[i + 1]) and (ans[i] < ans[i - 1]));
    }
    cout << c << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
//1 2 2     3 4 4 5
// 4 2 5 2 4 1 3
// _ 5 _ 4 _ 4 _
