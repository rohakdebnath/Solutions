#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct EBCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;
    
    EBCC() {}
    EBCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1); // dfs tree visit time (not distance from root)
        low.resize(n); //the value of the lowest entry node any descendent or itself can reach through a backedge
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                dfs(y, x);
                low[x] = min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    vector<int> work() { // runs a dfs with tarjan's bridge algorithm and returns the labels of each node
        dfs(0, -1);
        return bel;
    }
    
    struct Graph {
        int n;
        vector<pair<int, int>> edges;
        vector<int> siz;
        vector<int> cnte;
    };
    Graph compress() { // returns a tree with nodes representing a biconnected componet, siz is the size of such component and cnte is number of edges in such component
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto j : adj[i]) {
                if (bel[i] < bel[j]) {
                    g.edges.emplace_back(bel[i], bel[j]);
                } else if (i < j) {
                    g.cnte[bel[i]]++;
                }
            }
        }
        return g;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    EBCC g (n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        g.addEdge(u, v);
    }
    g.work();
    auto f = g.compress();
    vector<vector<int>> adj (f.n);
    for (auto [u, v]: f.edges){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> size(f.n);
    i64 ans = 0;
    auto dfs = [&] (auto&& self, int v, int p) -> void {
        size[v] = f.siz[v];
        for (int u: adj[v]){
            if (u == p) continue;
            self(self, u, v);
            size[v] += size[u];
            ans = max<i64>(ans, 1LL * size[u] * (n - size[u]));
        }
        return;
    };  
    dfs(dfs, 0, -1);
    cout << 1LL * n * (n - 1) / 2 - ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
