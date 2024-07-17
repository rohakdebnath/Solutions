#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void setIO(string name = "")
{
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    setIO("odometer");
    string x, y; cin >> x >> y;
    x = to_string(stoll(x) - 1);
    auto work = [&] (string s) -> int {
        int n = s.size();
        map<tuple<int, int, vector<int>>, i64> dp;
        auto ddp = [&] (auto&& self, int i, bool t, vector<int> f) -> i64 {
            if (i == n) {
                return *max_element(f.begin(), f.end()) >= (n + 1) / 2;
            }
            auto key = make_tuple(i, t, f);
            if (dp.find(key) != dp.end()) {
                return dp[key];
            }
            int limit = t ? s[i] - '0' : 9;
            i64 res = 0;
            for (int d = 0; d <= limit; ++d) {
                f[d]++;
                res += self(self, i + 1, t and (d == limit), f);
                f[d]--;
            }
            return dp[key] = res;
        };
        vector<int> f(10, 0);
        return ddp(ddp, 0, true, f);
    };
    cout << work(y) - work(x) << '\n';
    return 0;
}
