#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> v;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            v.push_back(i);
            v.push_back(x / i);
        }
    }
    sort(v.begin(), v.end());
    int m = v.size();
    map<int, int> f;
    f[1] = 1;
    int seg = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (!f[v[j]] and f[v[j] / a[i]] and v[j] % a[i] == 0) f[v[j]] = f[v[j] / a[i]];
        }
        if (f[x]) {
            ++seg;
            f.clear();
            f[1] = 1;
            f[a[i]] = 1;
        }
    }
    cout << seg << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
