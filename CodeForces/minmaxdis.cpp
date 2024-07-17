#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, K; cin >> N >> K;
    vector<int> mark (N);
    rep(i, 0, K){
        int x; cin >> x; --x;
        mark[x] = 1;
    }
    vector<vector<int>> adj (N);
    rep(i, 0, N - 1){
        int x, y; cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> dis (N);
    auto bfs = [&] (int x) -> int {
        queue<int> q;
        q.push(x);
        dis.assign(N, -1);
        dis[x] = 0;
        while (!q.empty()){
            int p = q.front();
            q.pop();
            for (int u: adj[p]){
                if (dis[u] == -1){
                    dis[u] = dis[p] + 1;
                    q.push(u);
                }
            }
        }
        int t = -1;
        rep(i, 0, N){
            if ((t == -1 or dis[i] > dis[t]) and mark[i]){
                t = i;
            }
        }
        return t;
    };
    int a = bfs(0);
    int b = bfs(a);
    auto f = dis;
    bfs(b);
    rep(i, 0, N) f[i] = max(f[i], dis[i]);
    cout << *min_element(all(f)) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
