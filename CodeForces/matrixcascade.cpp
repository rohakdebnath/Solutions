//common bitset W
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    bitset<3000> curr, l, r;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        l <<= 1;
        r >>= 1;
        curr ^= l ^ r;
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            if (curr[j] ^ (c == '1')){
                curr[j] = !curr[j];
                l[j] = !l[j];
                r[j] = !r[j];
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
