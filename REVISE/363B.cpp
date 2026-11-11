#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    int s = accumulate(a.begin(), a.begin() + k, 0LL);
    int ans = s;
    int j = 1;
    for (int i = k; i < n; ++i) {
        s = s - a[i - k] + a[i];
        if (s < ans) {
            ans = s;
            j = i - k + 2;
        }
    }
    cout << j << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

