#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int n, m;
vector<vector<int>> adj;

vector<bool> vis;
vector<int> tin, low; // tin is time for first visit, low is the tin of a backedge through a descendent (wrt the dfs tree)
int timer = 0, bridges = 0;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (int u: adj[v]){
        if (u == p) continue;
        if (vis[u]) low[v] = min(low[v], tin[u]); //we are looking for any backedge, tin[u] is used instead of low[u] because low[u] can introduce non existent backedges. Note that a visited u is not a direct descendent, so taking the backedges through any descendent (of u) of a non descendent (of v) can create illusions of backedges, instead taking the tin of u is safe since u has obviously a backedge since it's viisted already. This is enough for the algorithm, but just for understanding purposes, it may be possible that there is an even smaller reachable node when we would have taken low[u] instead of tin[u] but using low[u] is not only sometimes wrong, it is clearly unnecessary.
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) ++bridges;
        }
    }
}

int main()
{
    UNSYNC
    cin >> n >> m;
    adj.resize(n);
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    rep(i, 0, m){
        int x, y; cin >> x >> y; --x, --y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    dfs(0, -1);
    cout << bridges << '\n';
    return 0;
}
