#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    vector<vector<int>> grid (2, vector<int> (N)), vis (2, vector<int> (N));
    rep(i, 0, 2){
        rep(j, 0, N){
            char c; cin >> c; 
            grid[i][j] = (c == '>' ? 1 : -1);
        }
    }
    auto dfs = [&] (auto &&self, int x, int y) -> void {
        if (vis[x][y]) return;
        vis[x][y] = 1;
        for (auto [nx, ny] : vector<pair<int, int>> {{!x, y}, {x, y - 1}, {x, y + 1}}){
            if (0 <= ny and ny < N){
                ny += grid[nx][ny];
                self(self, nx, ny);
            }
        }
    };
    dfs(dfs, 0, 0);
    cout << (vis[1][N - 1]? "YES\n" : "NO\n");
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
