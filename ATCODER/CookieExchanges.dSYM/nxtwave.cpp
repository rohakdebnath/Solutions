#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b; cin >> a >> b;
    if (a == b) cout << "1\n";
    else if ((a + b) % 2 == 0) cout << "3\n";
    else cout << "2\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
