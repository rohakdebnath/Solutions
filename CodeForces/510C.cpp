#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> adj (26);


    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int t = 0;
            while ((t < min(a[i].size(), a[j].size())) and (a[i][t] == a[j][t])) ++t;
            if (t == min(a[i].size(), a[j].size())) {
                if (a[i].size() <= a[j].size()) continue;
                else {
                    cout << "Impossible\n";
                    return;
                }
            } 

            adj[a[i][t] - 'a'].push_back(a[j][t] - 'a'); //small to large edge
        }
    }

    vector<int> topo;
    queue<int> q;
    vector<int> in (26);
    for (auto& nodes: adj) {
        for (int u: nodes) ++in[u];
    }
    for (int i = 0; i < 26; ++i) {
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for (int u: adj[curr]) {
            if (--in[u] == 0) q.push(u);
        }
    }

    if (topo.size() != 26) cout << "Impossible\n";
    else {
        for (int i = 0; i < 26; ++i) {
            cout << char(topo[i] + 'a');
        }
        cout << '\n';
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    
    return 0;
}
