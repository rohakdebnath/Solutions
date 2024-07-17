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
    int H, W, N; cin >> H >> W >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<vector<int>> grid (H, vector<int> (W));
    int k = 0;
    rep(i, 0, H){
        rep(j, 0, W){
            grid[i][j] = A[k] ? k + 1 : ++k + 1;
            --A[k];
        }
        if (i & 1){
            reverse(all(grid[i]));
        }
    }
    rep(i, 0, H){
        rep(j, 0, W){
            cout << grid[i][j] << " \n"[j == W - 1];
        }
    }

    return 0;
}
