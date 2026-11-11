#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<string> s (n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << s[i].find_first_of('#') + 1 << " \n"[i == 0]; 
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
