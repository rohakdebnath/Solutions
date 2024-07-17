#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int m = 300;
    for (int i = 0; i < n - 1; ++i) {
        vector<int> x (n - 1);
        for (int j = 0; j < i; ++j) {
            x[j] = s[j] - '0';
        }
        x[i] = 10 * (s[i] - '0') + s[i + 1] - '0';
        for (int j = i + 2; j < n; ++j) {
            x[j - 1] = s[j] - '0';
        }
        if (find(x.begin(), x.end(), 0) != x.end()){
            m = 0;
            break;
        } else if (count(x.begin(), x.end(), 1) == n - 1) {
            m = min(m, 1);
        } else {
            int t = accumulate(x.begin(), x.end(), 0, [&] (int p, int e) {return p + (e != 1 ? e : 0);});
            m = min(m, t);
        }
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
