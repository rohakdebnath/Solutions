#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<vector<int>> grid, both, vis;
vector<int> FR, FC, R, C;
int N, M, maxR, maxC, minR, minC, S;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int i, int j){
    if (i <= 0 or j <= 0 or i > N or j > M or vis[i][j] or !grid[i][j]) return;
    vis[i][j] = 1;
    ++S;
    maxR = max(maxR, i);
    maxC = max(maxC, j);
    minR = min(minR, i);
    minC = min(minC, j);
    rep(t, 0, 4){
        int ni = dx[t] + i, nj = dy[t] + j;
        dfs(ni, nj);
    }
    return;
}

void solve()
{
    cin >> N >> M;
    R.assign(N + 2, 0);
    C.assign(M + 2, 0);
    FR.assign(N + 2, 0);
    FC.assign(M + 2, 0);
    both.assign(N + 2, vector<int> (M + 2));
    vis.assign(N + 2, vector<int> (M + 2, 0));
    grid.assign(N + 2, vector<int> (M + 2));

    rep(i, 1, N + 1){
        rep(j, 1, M + 1){
            char c; cin >> c;
            grid[i][j] = (c == '#');
            if (c == '.') FR[i]++, FC[j]++;
        }
    }

    rep(i, 1, N + 1){
        rep(j, 1, M + 1){
            if (vis[i][j] or !grid[i][j]) continue;
            S = 0;
            minR = INT32_MAX;
            minC = INT32_MAX;
            maxR = -INT32_MAX;
            maxC = -INT32_MAX;
            dfs(i, j);
            minR = max(1, minR - 1);
            maxR = min(N, maxR + 1);
            minC = max(1, minC - 1);
            maxC = min(M, maxC + 1);

            R[minR] += S; R[maxR + 1] -= S;
            C[minC] += S; C[maxC + 1] -= S;

            both[minR][minC] += S;
            both[minR][maxC + 1] -= S;
            both[maxR + 1][minC] -= S;
            both[maxR + 1][maxC + 1] += S;
        }
    }
    rep(i, 1, N + 1) R[i] += R[i - 1];
    rep(i, 1, M + 1) C[i] += C[i - 1];
    rep(i, 1, N + 1) rep(j, 1, M + 1) both[i][j] += both[i - 1][j] + both[i][j - 1] - both[i - 1][j - 1];

    int ans = 0;

    rep(i, 1, N + 1){
        rep(j, 1, M + 1){
            ans = max(ans, FR[i] + FC[j] - !grid[i][j] + R[i] + C[j] - both[i][j]);
        }
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
