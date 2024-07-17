#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int c = 0;
    int e = n;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '9' and c) {
            s[i] = '0';
            continue;
        }
        s[i] += c;
        c = 0;
        if (s[i] >= '5') {
            s[i] = '0';
            c = 1;
            e = i;
        }
    }
    if (c) cout << '1';
    for (int i = 0; i < e; ++i) {
        cout << s[i];
    }
    for (int i = e; i < n; ++i) {
        cout << '0';
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
