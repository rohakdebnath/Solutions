#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int M = 2e5 + 1;
vector<int> adj[M];
int ans[M], dis[M];

void dfs(int n, int p){
    for (int u: adj[n]){
        if (u == p) continue;
        ans[u] = (ans[n] + 1) % 2;
        dis[u] = (dis[n] + 1) % 2;
        dfs(u, n);
        if (ans[u] ^ dis[n]) ans[n] = ans[u];
    }
}

int main()
{
    UNSYNC
    int N, T; cin >> N >> T;
    rep(i, 0, N - 1){
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans[0] = 0, dis[0] = 0;
    dfs(0, -1);
    rep(i, 0, T){
        int t; cin >> t; --t;
        cout << (ans[t] ^ dis[t] ? "Ron\n": "Hermione\n");
    }
    return 0;
}
