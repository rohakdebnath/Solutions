#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj (n);
    map<array<int, 2>, int> id;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        id[{a, b}] = i;
        id[{b, a}] = i;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ec (n - 1);
    auto dfs = [&] 
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
