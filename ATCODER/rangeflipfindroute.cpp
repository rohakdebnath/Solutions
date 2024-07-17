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

int main()
{
    UNSYNC
    int N, M; cin >> N >> M;
    VVI grid (N, VI (M));
    rep(i, 0, N){
        string s; cin >> s;
        rep(j, 0, M){
            grid[i][j] = (s[j] == '#');
        }
    }

    VVI shortpath (N, VI (M, INT32_MAX));

    rep(i, 0, N){
        rep(j, 0, M){
            if (i == 0 and j == 0){
                shortpath[i][j] = grid[i][j];
            } else {
                if (i > 0){
                    shortpath[i][j] = min(shortpath[i][j], shortpath[i - 1][j] + (grid[i][j] == 1 and grid[i - 1][j] == 0));
                }
                if (j > 0){
                    shortpath[i][j] = min(shortpath[i][j], shortpath[i][j - 1] + (grid[i][j] == 1 and grid[i][j - 1] == 0));
                }
            }
        }
    }
    cout << shortpath[N - 1][M - 1] << '\n';
    return 0;
}
