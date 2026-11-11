#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct Node {
    i64 sum = 0, pref = -(1LL << 60), suff = pref, best = pref;
};

Node operator+(Node a, Node b) {
    return {a.sum + b.sum, max(a.pref, a.sum + b.pref),
            max(b.suff, b.sum + a.suff), max({a.best, b.best, a.suff + b.pref})};
}

void solve() {
    int n; cin >> n;
    vector<Node> t(2 * n);
    for (int i = 0; i < n; ++i) {
        i64 x; cin >> x;
        t[n + i] = {x, x, x, x};
    }
    for (int i = n - 1; i; --i) t[i] = t[2 * i] + t[2 * i + 1];

    auto query = [&](int l, int r) {
        Node a, b;
        for (l += n - 1, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) a = a + t[l++];
            if (r & 1) b = t[--r] + b;
        }
        return a + b;
    };
    
    int m; cin >> m;
    while (m--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        auto a = query(x1, x2 - 1), b = query(x2, y1), c = query(y1 + 1, y2);
        cout << max({b.best, a.suff + b.pref, b.suff + c.pref,
                     a.suff + b.sum + c.pref}) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
