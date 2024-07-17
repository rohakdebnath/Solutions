#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

VVI adj;
bitset<200000> vis;
VI color;
int siz = 0;
void dfs(int s, int c){
    vis[s] = 1;
    if (!c) color[s] = 1, ++siz;
    for (int u: adj[s]) if (!vis[u]) dfs(u, !c);
}

void solve()
{
    int n, m; cin >> n >> m;
    adj = VVI (n);
    vis.reset();
    color = VI (n);
    siz = 0;
    
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0); //one dfs is enough since bro said connected graph
    if (siz <= n/2){
        cout << siz << '\n';
        rep(i, 0, n) if (color[i]) cout << i + 1 << ' ';
    } else {
        cout << n - siz << '\n';
        rep(i, 0, n) if (!color[i]) cout << i + 1 << ' ';
    }
    
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
