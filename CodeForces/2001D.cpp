//Inspired from Find the lexicographically smallest subsequence of an array such that all the unique elements appear exactly once.
//0 <= a[i] < n
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> f (n + 1);
    vector<int> vis (n + 1);
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], ++f[a[i]];
    vector<int> ans (n); ans[0] = a[0]; --f[a[0]]; vis[a[0]] = 1;

    auto check = [&] (int j, int num) {
        if (j % 2 == 0) return num > ans[j];
        return num < ans[j];
    };
    int j = 1;
    for (int i = 1; i < n; ++i) {
        f[a[i]]--;
        if (vis[a[i]]) continue;
        while ((j > 0 and check(j - 1, a[i]) and f[ans[j - 1]] > 0) or (j > 1 and check(j - 2, a[i]) and f[ans[j - 2]] * f[ans[j - 1]] > 0)) {
            if (j > 0 and check(j - 1, a[i]) and f[ans[j - 1]] > 0) {
                vis[ans[j - 1]] = 0;
                --j;
            } else {
                vis[ans[j - 1]] = vis[ans[j - 2]] = 0;
                j -= 2;
            }
        }
        ans[j] = a[i];
        vis[a[i]] = 1;
        ++j;
    }
    cout << j << '\n';
    for (int i = 0; i < j; ++i) {
        cout << ans[i] << " \n"[i == j - 1];
    }
}   

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
