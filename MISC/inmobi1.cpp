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
    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        Node a, b;
        for (l += n - 1, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) a = a + t[l++];
            if (r & 1) b = t[--r] + b;
        }
        cout << (a + b).best << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
