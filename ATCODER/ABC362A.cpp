#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<int> c (3);
    for (int i = 0; i < 3; ++i) {
        cin >> c[i];
    }
    string s; cin >> s;
    if (s == "Red") {
        cout << min(c[1], c[2]);
    } else if (s == "Blue") {
        cout << min(c[0], c[1]);
    } else {
        cout << min(c[0], c[2]);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
