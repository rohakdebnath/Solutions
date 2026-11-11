#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int h, w; cin >> h >> w;

    vector<set<int>> row(h), col(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    int ans = h * w;
    
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y; --x, --y;
        
        if (row[x].count(y)) {
            --ans;
            row[x].erase(y), col[y].erase(x);
        } else {
            auto it = row[x].lower_bound(y);
            if (it != row[x].begin()) {
                int b = *prev(it);
                --ans;
                row[x].erase(b), col[b].erase(x);
            }
            if (it != row[x].end()) {
                int b = *it;
                --ans;
                row[x].erase(b), col[b].erase(x);
            }

            it = col[y].lower_bound(x);
            if (it != col[y].begin()) {
                int a = *prev(it);
                --ans;
                row[a].erase(y), col[y].erase(a);
            }
            if (it != col[y].end()) {
                int a = *it;
                --ans;
                row[a].erase(y), col[y].erase(a);
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
