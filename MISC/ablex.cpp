#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s, ans = ""; cin >> s; s += 'z';
    int n = s.size();
    vector<int> f (26); for (int i = 0; i < n; ++i) ++f[s[i] - 'a'];
    stack<char> t;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (f[j] == 0 and j < 26) ++j;
        while (!t.empty() and t.top() < j + 'a') {
            ans += t.top();
            t.pop();
        }
        if (s[i] == j + 'a') ans += s[i];
        else t.push(s[i]);
        --f[s[i] - 'a'];
    }
    cout << ans.substr(0, n - 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
