#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, K; cin >> N >> K;
    vector<vector<int>> adj (N);
    rep(i, 0, N - 1){
        int x, y; cin >> x >> y; --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto check = [&] (int m) -> bool {
        int cc = 0;
        auto dfs = [&] (auto &&self, int v, int p) -> int {
            int sz = 1;
            for (int u: adj[v]){
                if (u == p) continue;
                sz += self(self, u, v);
            }
            if (sz >= m){
                sz = 0;
                ++cc;
            }
            return sz;
        };
        dfs(dfs, 0, -1);
        return cc > K;
    };

    int l = 0, r = 1;
    while (check(r)) r *= 2;
    while (r - l > 1){
        int m = l + (r - l) / 2;
        if (check(m)){
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}

