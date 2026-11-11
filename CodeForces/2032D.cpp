#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int r; cin >> r;
    return r;
}

void solve() {
    int n; cin >> n;
    vector<int> p (n);
    int x = 2;
    while (query(x, 1)) ++x;
    p[x] = 1;
    int y = 2;
    for (int i = x + 1; i < n; ++i) {
        while (query(i, y)) ++y;
        p[i] = y++;
    }
    cout << "!";
    for (int i = 1; i < n; i++) {
        cout << " " << p[i];
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
