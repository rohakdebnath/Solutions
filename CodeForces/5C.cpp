#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    map<int, int, greater<int>> id;
    id[0] = 0;
    int x = 0, m = 0, c = 1;
    for (int i = 0; i < n; ++i) {
        x += 2 * (s[i] == '(') - 1;
        if (id.find(x) == id.end()) id[x] = i + 1;
        else if (i + 1 - id[x] > m) {
            c = 1;
            m = i + 1 - id[x];
        } else if (i + 1 - id[x] == m) {
            ++c;
        }
        while (id.begin() -> first > x) id.erase(id.begin());
    }
    cout << m << ' ' << c << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
