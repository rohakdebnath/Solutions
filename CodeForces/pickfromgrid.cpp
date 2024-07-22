#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g (n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    //checks if the each array has atleast one element where the bth bit if off or not
    auto check = [&] (int b) -> bool { 
        vector<vector<int>> v (n);
        for (int i = 0; i < n; ++i) {
            for (int x: g[i]) {
                if ((x & (1 << b)) == 0) {
                    v[i].push_back(x);
                }
            }
            if (v[i].size() == 0) return false;
        }
        g = v;
        return true;
    };
    int ans = 0;
    for (int b = 31; b >= 0; --b) {
        if (!check(b)) ans |= (1 << b);
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
