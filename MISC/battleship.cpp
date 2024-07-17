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

char grid[101][101];
bool vis [101][101];
int N;
int T, x = 1;

void dfs (int i, int j){
    if (i < 0 or i >= N or j < 0 or j >= N or grid[i][j] == '.' or vis[i][j]) return;
    vis[i][j] = 1;
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i + 1, j);
}
void solve()
{
    cin >> N;
    memset(vis, 0, sizeof(vis));
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> grid[i][j];
        }
    }
    cout << "Case " << x << ": ";
    int ans = 0;
    rep(i, 0, N){
        rep(j, 0, N){
            if (!vis[i][j] and grid[i][j] == 'x'){
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    cin >> T;
    for(; x < T + 1; ++x){
        solve();
    }
    return 0;
}
