#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 a, b; cin >> a >> b; --a;
    vector<vector<i64>> rxor = {{a, 1, a + 1, 0}, {b, 1, b + 1, 0}};
    if (a == -1) {
        cout << rxor[1][b % 4] << '\n';
        return;
    }
    cout << (rxor[1][b % 4] ^ rxor[0][a % 4]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
