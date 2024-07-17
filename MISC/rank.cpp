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
bitset<20> cycled;
int vis[20];

void dfs(int ini, int s){
    if (vis[s]) return;
    ++vis[s];
    for(auto u: adj[s]){
        if (u == ini){
            cycled[ini] = 1;
            return;
        }
        dfs(ini, u);
    }
    return;
}
int main()
{
    UNSYNC
    int N, K; cin >> N >> K;
    adj.resize(N);
    rep(i, 0, K){
        int a, b, s_a, s_b; cin >> a >> b >> s_a >> s_b;
        --a, --b;
        if (s_a > s_b){
            adj[a].push_back(b);
        } else {
            adj[b].push_back(a);
        }
    }
    rep(i, 0, N){
        memset(vis, 0, sizeof(vis));
        dfs(i, i);
    }
    cout << cycled.count() << '\n';
    return 0;
}
