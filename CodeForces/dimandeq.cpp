#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 a, b, c; cin >> a >> b >> c;
    auto sum = [&] (i64 n) ->i64 {
        i64 s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    };
    vector<int> ans;
    for (i64 i = 1; i <= 81; ++i) {
        i64 x = b * powl(i, a) + c;
        i64 sx = sum(x);
        if (i == sx and 0 < x and x < 1e9) ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
