#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<int> a (6), b (6);
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 6; ++i) {
        cin >> b[i];
    }
    auto intersect = [&] (int x1, int x2, int y1, int y2) {
        return min(x2, y2) > max(x1, y1);
    };
    bool srv = 1;
    for (int i = 0; i < 3; ++i) {
        if (!intersect(a[i], a[i + 3], b[i], b[i + 3])) srv = 0;
    }
    cout << (srv ? "Yes\n" : "No\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
