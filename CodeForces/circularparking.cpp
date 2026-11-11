#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i]; 
    vector<int> next(n);
    iota(next.begin(), next.end(), 0);

    auto find = [&] (auto&& self, int x) -> int {
        if (next[x] != x) next[x] = self(self, next[x]);
        return next[x];
    };

    for (int i = 0; i < n; ++i) {
        int x = find(find, a[i]), y = find(find, (x + 1) % n);
        cout << x + 1 << " \n"[i == n - 1];
        next[a[i]] = next[x] = y;
    }

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
