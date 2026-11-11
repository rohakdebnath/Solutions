#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int ask (int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    return x;
}
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 2; i <= n; ++i) {
        int node = 1;
        while (true) {
            int x = ask(i, node);
            if (x == i) {
                ans.push_back({i, node});
                break;
            }
            node = x;
        }
    }
    cout << "! ";
    for (auto [u, v]: ans) {
        cout << u << ' ' << v << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
