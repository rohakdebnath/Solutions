#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t = "";
    int l = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            l = 1;
            t += '1';
        } 
        else if (s[i] == '0' and l) {
            l = 0;
            t += '0';
        }
    }
    n = t.size();
    int x = count(t.begin(), t.end(), '0');
    cout << (x >= (n + 1) / 2 ? "No\n": "Yes\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
