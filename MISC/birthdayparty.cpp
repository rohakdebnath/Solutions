#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int n, m;

bool adj[101][101];
bitset<101> vis;

void dfs(int s){
    if (vis[s]) return;
    vis[s] = true;
    rep(i, 0, n){
        if (adj[s][i]) dfs(i);
    }
    return;
}

int main()
{
    UNSYNC
    while (cin >> n >> m and (n or m)){
        memset(adj, false, sizeof(adj));
        vector<pair<int, int>> edges;
        rep(i, 0, m){
            int a, b; cin >> a >> b;
            adj[a][b] = adj[b][a] = 1;
            edges.push_back({a, b});
        }
        bool survive = true;
        for (auto p: edges){
            adj[p.first][p.second] = adj[p.second][p.first] = 0;
            vis.reset();
            dfs(0);
            rep(i, 0, n){
                if (!vis[i]){
                    survive = false;
                    break;
                }
            }
            adj[p.first][p.second] = adj[p.second][p.first] = 1;
        }
        cout << (survive ? "No\n": "Yes\n");
    }
    return 0;
}
