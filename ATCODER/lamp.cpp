#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int H, W; cin >> H >> W;
    int grid[2000][2000];
    rep(i, 0, H){
        rep(j, 0, W){
            char c; cin >> c;
            grid[i][j] = (c == '.');
        }
    }
    int L[2000][2000];
    int R[2000][2000];
    int U[2000][2000];
    int D[2000][2000];

    rep(i, 0, H){
        rep(j, 0, W){
            if (j == 0) L[i][j] = grid[i][j];
            else if (grid[i][j] == 0) L[i][j] = 0;
            else L[i][j] = 1 + L[i][j - 1];
        }
    }
    rep(i, 0, H){
        per(j, W - 1, 0){
            if (j == W - 1) R[i][j] = grid[i][j];
            else if (grid[i][j] == 0) R[i][j] = 0;
            else R[i][j] = 1 + R[i][j + 1];
        }
    }
    rep(j, 0, W){
        rep(i, 0, H){
            if (i == 0) U[i][j] = grid[i][j];
            else if (grid[i][j] == 0) U[i][j] = 0;
            else U[i][j] = 1 + U[i - 1][j];
        }
    }
    rep(j, 0, W){
        per(i, H - 1, 0){
            if (i == H - 1) D[i][j] = grid[i][j];
            else if (grid[i][j] == 0) D[i][j] = 0;
            else D[i][j] = 1 + D[i + 1][j];
        }
    }

    int ans = 0;
    rep(i, 0, H){
        rep(j, 0, W){
            if (grid[i][j]) ans = max(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
        }
    }
    cout << ans << '\n';
    return 0;
}
