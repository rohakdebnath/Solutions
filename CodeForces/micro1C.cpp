#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, I; cin >> n >> I;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    //K <= 2 ^ 8I/n
    int K = 8 * I / n >= 20 ? n : min(n, (1 << 8 * I / n));

    int l = -1, j = 0, f = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == l) continue;
        while (j < n and f < K) {
            f += a[j] != (j - 1 >= 0 ? a[j - 1] : -1);
            ++j;
        }
        while (j < n and a[j] == a[j - 1]) ++j;
        ans = max(ans, j - i);
        l = a[i];
        --f;
    }
    cout << n - ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
