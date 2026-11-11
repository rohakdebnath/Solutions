//Find the lexicographically smallest subsequence of an array such that all the unique elements appear exactly once.
//0 <= a[i] < n
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> f (n);
    vector<int> vis (n);
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], ++f[a[i]];
    vector<int> ans (n); ans[0] = a[0]; --f[a[0]]; vis[a[0]] = 1;

    int j = 1;
    for (int i = 1; i < n; ++i) {
        f[a[i]]--;
        if (vis[a[i]]) continue;
        while (j > 0 and ans[j - 1] > a[i] and f[ans[j - 1]] > 0) {
            vis[ans[j - 1]] = 0;
            --j;
        }
        ans[j++] = a[i];
        vis[a[i]] = 1;
    }
    for (int i = 0; i < j; ++i) {
        cout << ans[i] << " \n"[i == j - 1];
    }
}   

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
