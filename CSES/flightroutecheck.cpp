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

VI adj[100001][2];
bitset<100001> vis;

void dfs(int s, int i){
    vis[s] = true;
    for(int u: adj[s][i]) if (!vis[u]) dfs(u, i);
}

int main() //directed graph prob. main idea is that we claim that if we can go anywhere from any particular node and also reach that node from any other node, then it is possible to go from anywhere to everywhere.
{
    UNSYNC
    int n, m; cin >> n >> m;

    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a); // adj[x][1] represents the reverse graph, this is a wonderful concept and the proof is there is usaco internal sols.
    }

    dfs(0, 0);
    rep(i, 0, n) if (!vis[i]) {cout << "NO\n" << 1 << ' ' << i + 1 << '\n'; return 0;}
    vis.reset();
    dfs(0, 1);
    rep(i, 0, n) if (!vis[i]) {cout << "NO\n" << i + 1 << ' ' << 1 << '\n'; return 0;}

    cout << "YES\n";
    return 0;
}
