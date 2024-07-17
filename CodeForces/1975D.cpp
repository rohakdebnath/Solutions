#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MX = 2e5 + 1;
vector<int> adj[MX];
int d[MX], p[MX];

void dfs(int i, int par){
    for (int u: adj[i]){
        if (u == par) continue;
        d[u] = d[i] + 1;
        p[u] = i;
        dfs(u, i);
    }
    return;
}

void solve()
{
    int N; cin >> N;
    int a, b; cin >> a >> b; --a, --b;
    rep(i, 0, N){
        adj[i].clear();
    }
    rep(i, 0, N - 1){
        int x, y; cin >> x >> y; --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    d[a] = 0;
    dfs(a, -1);
    int dis = (d[b] + 1) / 2;
    int v = b;
    rep(i, 0, dis) v = p[v];
    d[v] = 0;
    dfs(v, -1);
    cout << 2 * (N - 1) - *max_element(d, d + N) + dis << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
