#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    string s; cin >> s;

    vector<int> id (n); iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {return a[i] < a[j];});
    vector<int> pid (n);
    for (int i = 0; i < n; ++i) pid[id[i]] = i;

    vector<vector<int>> adj (n);
    for (int i = 0; i < n; ++i) {
        adj[a[i]].push_back(pid[a[i]]);
        adj[pid[a[i]]].push_back(a[i]);
    }
    
    vector<int> vis (n);
    auto dfs = [&] (auto&& self, int v, vector<int>& cc) -> void{
        cc.push_back(v);
        vis[v] = 1;
        for (int u: adj[v]) {
            if (!vis[u]) self(self, u, cc);
        }
    };
    vector<int> ans (n);
    for (int i = 0; i < n; ++i) {
        vector<int> cc;
        if (!vis[i]) {
            dfs(dfs, i, cc);
        }   
        int c = 0;
        for (int x: cc) {
            c += s[x] == '0';
        }
        for (int x: cc) {
            ans[x] = c;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
