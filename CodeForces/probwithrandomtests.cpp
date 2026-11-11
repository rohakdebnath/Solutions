#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e6;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (count(s.begin(), s.end(), '0') == n) {
        cout << "0\n";
        return;
    }
    s = s.substr(s.find_first_of('1'));
    n = s.size();
    bitset<inf> b;
    for (int i = 0; i < n; ++i) {
        b[inf - i - 1] = s[i] - '0';
    }

    string x = "0";
    int fz = 0;
    for (int i = 0; i < 21; ++i) {
        bitset<inf> t = (b | (b >> i));
        int ts = 0;
        while (t[inf - ts - 1] == 1) ++ts;
        if (ts > fz) {
            x = t.to_string();
            fz = ts;
        }
    }
    x = x.substr(0, n);
    cout << x << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
