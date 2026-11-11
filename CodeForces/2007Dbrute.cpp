#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    int m = 0;
    vector<int> vis (n);
    auto maxrec = [&] (auto&& self, int c, int pt) ->void{
        if (c == k) {
            if (accumulate(a.begin(), a.end(), 0, [&] (int s, int i) {
                return s + (i > 0);
            }) < k - c) return;
            vis = vector<int> (n);
            c = 0;
            m = max(m, pt);
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i] and a[i]) {
                --a[i];
                vis[i] = 1;
                self(self, c + 1, pt + 1);
                ++a[i];
                vis[i] = 0;
            }
        }
    };  
    maxrec(maxrec, 0, 0);
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
