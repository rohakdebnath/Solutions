#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> dlm (36);
    dlm[0] = 1;
    for (i64 i = 1; i < 36; ++i) {
        dlm[i] = 9 * powl(10, ceil((i - 2) / 2.0));
    }
    partial_sum(dlm.begin(), dlm.end(), dlm.begin());
    i64 x = upper_bound(dlm.begin(), dlm.end(), n) - dlm.begin() - 1;
    n -= dlm[x] + 1;
    i64 ans = powl(10, x / 2) + n;
    
    string s = to_string(ans);
    string t = s.substr(0, s.size() - ((x + 1) & 1));
    reverse(t.begin(), t.end());
    s += t;
    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
