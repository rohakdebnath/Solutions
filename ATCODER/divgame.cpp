#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e5;
void solve() {
    vector<int> g (inf + 1);
    for (int i = 2; i <= inf; ++i) {
        map<int, bool> f; 
        f[g[1]] = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                f[g[j]] = f[g[i / j]] = 1;
            }
        }
        int mex = 0;
        while (f[mex] == 1) ++mex;
        g[i] = mex;
    }
    int xsum = 0;
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], xsum ^= g[a[i]];
    cout << (xsum == 0 ? "Bruno\n": "Anna\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
