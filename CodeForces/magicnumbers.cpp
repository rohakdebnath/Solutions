#include <bits/stdc++.h>

using namespace std;
using i64 = long long;


const int mod = 1e9 + 7;
void solve() {
    int m, x; cin >> m >> x;
    string l, r; cin >> l >> r;
    int n = r.size();
    while (l.size() < n) l = '0' + l;

    vector<int> p(n, 1);
    for(int i = n - 2; i >= 0; --i){
        p[i] = (p[i + 1] * 10) % m;
    }

    vector ddp(n, vector (2, vector (2, vector<int> (m, -1)))); 
    auto dfs = [&] (auto&& self, int i, int over, int under, int rem) -> int {
        if (i == n) return (rem == 0);
        if (ddp[i][over][under][rem] != -1) return ddp[i][over][under][rem];

        int o = over ? l[i] - '0' : 0;
        int u = under ? r[i] - '0' : 9;

        int res = 0;
        for (int d = o; d <= u; ++d) {
            if ((i % 2 == 1 and d != x) or ((i % 2 == 0 and d == x))) continue;
            int nrem = ((rem - d * p[i]) % m + m) % m;
            res = (res + self(self, i + 1, over and (d == o), under and (d == u), nrem)) % mod;
        }

        return ddp[i][over][under][rem] = res;
    };

    cout << dfs(dfs, 0, 1, 1, 0) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
