#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int x, y, z; cin >> x >> y >> z;
    auto dis = [&] (int m){
        return abs(m - x) + abs(m - y) + abs(m - z);
    };
    int mi = 1e9;
    for (int i = 0; i < 11; ++i) {
        mi = min(mi, dis(i));
    }
    cout << mi << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
