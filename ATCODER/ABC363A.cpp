#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int r; cin >> r;
    if (r <= 99) cout << 100 - r << '\n';
    else if (r <= 199) cout << 200 - r << '\n';
    else cout << 300 - r << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
