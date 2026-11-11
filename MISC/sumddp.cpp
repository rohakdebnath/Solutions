//Problem: Find the sum of all the numbers in the range l to r using digit dp, can be easily extended to problem such as "no digit 5", "no consecutive 2s" or "no pattern x" etc 
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string l, r; cin >> l >> r; 
    int n = r.size();
    while (l.size() < r.size()) l = '0' + l;
    vector ddp(n, vector (2, vector<array<int, 2>> (2, {-1, -1}))); //dp[i][j][k] = sum till the ith digit of the of all numbers which are within l and r, taken care by over and under

    auto dfs = [&] (auto&& self, int i, int over, int under) -> array<int, 2> {
        if (i == n) return {0, 1};
        auto s = ddp[i][over][under];
        if (s[0] != -1) return s;
        s = {0, 0};
        int o = over ? l[i] - '0' : 0;
        int u = under ? r[i] - '0' : 9;
        for (int d = o; d <= u; ++d) {
            auto p = self(self, i + 1, over and (d == o), under and (d == u));
            s[0] += pow(10, n - 1 - i) * d * p[1] + p[0];
            s[1] += p[1];
        }

        return ddp[i][over][under] = s;
    };
    cout << dfs(dfs, 0, 1, 1)[0] << '\n';

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
