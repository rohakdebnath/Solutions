#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> tri (2e5 + 1);
void pre() {
    auto f = [&] (int x) {
        int ans = 0;
        while (x) {
            x /= 3;
            ++ans;
        }
        return ans;
    };
    for (int i = 0; i <= 2e5; ++i) {
        tri[i] = f(i);
    }
}
void solve() {
    int l, r; cin >> l >> r;
    
    int ans = 0;
    for (int i = l; i <= r; ++i) ans += tri[i];
    cout << ans + tri[l] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
