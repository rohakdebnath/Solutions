//Problem: Count all the numbers in the range l to r which doesnt have the number 5 inside it
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string l, r; cin >> l >> r; 
    int n = r.size();
    while (l.size() < r.size()) l = '0' + l;
    vector ddp (n, vector (2, vector<int> (2, -1))); //ddp[i][j][k] = count of all n - i digit numbers which doesnt have the number 5 in it
    
    auto dfs = [&] (auto&& self, int i, int over, int under) {
        if (i == n) return 1;
        if (ddp[i][over][under] != -1) return ddp[i][over][under];

        int o = over ? l[i] - '0' : 0;
        int u = under ? r[i] - '0' : 9;

        int res = 0;
        for (int d = o; d <= u; ++d) {
            if (d == 5) continue;
            res += self(self, i + 1, over and (d == o), under and (d == u));
        }

        return ddp[i][over][under] = res;
    };

    cout << dfs(dfs, 0, 1, 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
