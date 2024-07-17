#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<array<int, 2>> a (3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
    vector<int> d (3);
    for (int i = 0; i < 3; ++i) {
        d[i] = pow(a[i][0] - a[(i + 1) % 3][0], 2) + pow(a[i][1] - a[(i + 1) % 3][1], 2);
    }
    sort(d.begin(), d.end());
    cout << (d[0] + d[1] == d[2] ? "Yes\n": "No\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
