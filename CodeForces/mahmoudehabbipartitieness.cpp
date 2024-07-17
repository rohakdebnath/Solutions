#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

VVI adj;
i64 one = 0, zero = 0;
bitset<100000> vis;

void dfs(i64 s, i64 c){
    vis[s] = 1;
    (c ? one : zero)++;
    for(i64 u : adj[s]) if (!vis[u]) dfs(u, !c);
    return;
}

int main()
{
    UNSYNC
    i64 n; cin >> n;
    adj.resize(n);
    rep(i, 0, n - 1){
        i64 a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0); //one dfs is enough since a tree is a single connected component anyway
    cout << one*zero - n + 1 << '\n';
    return 0;
}
