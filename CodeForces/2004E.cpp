#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e7;
vector<int> g (inf + 1);

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int xsum = 0;
    for (int i = 0; i < n; ++i) {
        xsum ^= g[a[i]];
    }
    cout << (xsum > 0 ? "Alice\n": "Bob\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    g[0] = 0, g[1] = 1;
    int primeid = 2;
    for (int i = 2; i <= inf; ++i) {
        if (i % 2 == 0 or g[i]) {
            continue;
        } else {
            g[i] = primeid++;
            for (int j = 2 * i; j <= inf; j += i) {
                g[j] = g[i];
            }
        }
    }
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
