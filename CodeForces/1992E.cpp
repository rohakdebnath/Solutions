#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> ans;
    string s = to_string(n);
    int l = s.size();
    for (int d = 1; d <= 6; ++d) {
        string t;
        for (int i = 0; i < d; ++i) {
            t += s[i % l];
        }
        int v = stoll(t);
        for (int a = 1; a <= 10000; ++a) {
            int b = n * a - v;
            if (1 <= b and b <= 10000 and l * a - b == d) {
                ans.push_back({a, b});
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto[u, v]: ans) {
        cout << u << ' ' << v << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
