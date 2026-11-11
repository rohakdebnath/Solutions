#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e4;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    //g[x] = mex(g[x - a[i] | x >= a[i] frall i (0..n - 1)]) //we can find all g(x) in O(n * k) which is sufficient for the problem at hand, hence pattern finding is not necessary
    vector<int> g (inf + 1);
    for (int i = 1; i <= inf; ++i) {
        map<int, int> s;
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) s[g[i - a[j]]] = 1;
        }
        int mex = 0;
        while (s[mex] == mex) ++mex;
        g[i] = mex;
    }
    for (int i = 0; i < 20; ++i) cout << g[i] << " \n"[i == 99];
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int xsum = 0;
        for (int i = 0; i < x; ++i) {
            int p; cin >> p;
            xsum ^= g[p];
        }
        cout << (xsum > 0 ? "W": "L");
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
