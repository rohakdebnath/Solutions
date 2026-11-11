#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e6;
vector<int> g (inf + 1);

void solve() {
    int n; cin >> n;
    int xsum = 0;
    while (n--) {
        int x; cin >> x;
        xsum ^= g[x];
    }
    cout << (xsum == 0 ? 2 : 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 2; i <= inf; ++i) {
        map<int, bool> s;
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                if (j < i) s[g[j]] = 1;
                if (i / j < i) s[g[i / j]] = 1;
            }
        }
        int mex = 0;
        while (s[mex]) ++mex;
        g[i] = mex;
    }
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
