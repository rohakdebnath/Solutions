#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == s[i]) {
            cout << s.substr(0, i) << (s[i] - 'a' + 1) % 26 + 'a' << s.substr(i) << '\n';
            return;
        }
    }
    cout << s << (s[n - 1] - 'a' + 1) % 26 + 'a' << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
