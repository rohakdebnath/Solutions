#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string a, b; cin >> a >> b;
    int n = b.size();
    while (int(a.size()) < n) a = '0' + a;
    auto prod = [&] (string s) -> i64{
        i64 p = 1;
        int i = 0;
        while(s[i] == '0') ++i;
        if (s.size() == 0) return -1;
        for (; i < n; ++i) {
            p *= (s[i] - '0');
        }
        return p;
    };
    string ans = b;
    int i = 0;
    while (a[i] == b[i]) ++i;
    for (; i <= n; ++i) {
        string t = b.substr(0, i);
        if (i < n) t += char(b[i] - 1);
        t += string(n - t.size(), '9');
        if (prod(t) > prod(ans)) ans = t;
    }
    while (ans[0] == '0') ans.erase(ans.begin());
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
