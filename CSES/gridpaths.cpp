#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MOD = 1e9 + 7;
int main()
{
    UNSYNC
    int N; cin >> N;
    char grid[1000][1000];
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> grid[i][j];
        }
    }

    int way[1000][1000];
    memset(way, 0, sizeof(way));
    way[0][0] = grid[0][0] == '.';
    rep(i, 0, N){
        rep(j, 0, N){
            if (grid[i][j] == '*') continue;
            if (i > 0) way[i][j] += way[i - 1][j], way[i][j] %= MOD;
            if (j > 0) way[i][j] += way[i][j - 1], way[i][j] %= MOD;
        }
    }
    cout << way[N - 1][N - 1] << '\n';
    return 0;
}
