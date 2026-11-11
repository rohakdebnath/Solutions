#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> a;
    priority_queue<int> pq;
    pq.push(n - 1);
    vector<int> vis (n); 
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        vis[x] = 1;
        a.push_back(x);
        for (int v: adj[x]) {
            if (!vis[v]) pq.push(v);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] + 1 << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
