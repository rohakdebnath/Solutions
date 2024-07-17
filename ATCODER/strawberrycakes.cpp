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
    int H, W, K; cin >> H >> W >> K;
    vector<vector<int>> ans (H, vector<int> (W));
    int strob = 1;
    rep(i, 0, H){
        rep(j, 0, W){
            char c; cin >> c;
            if (c == '#') ans[i][j] = strob++;
        }
    }

    rep(i, 0, H){
        rep(j, 1, W){
            if (ans[i][j] == 0) ans[i][j] = ans[i][j - 1];
        }
        per(j, W - 2, 0){
            if (ans[i][j] == 0) ans[i][j] = ans[i][j + 1];
        }
    }

    rep(i, 1, H){
        rep(j, 0, W){
            if (ans[i][j] == 0) ans[i][j] = ans[i - 1][j];
        }
    }
    per(i, H - 2, 0){
        rep(j, 0, W){
            if (ans[i][j] == 0) ans[i][j] = ans[i + 1][j];
        }
    }

    rep(i, 0, H){
        rep(j, 0, W) cout << ans[i][j] << " \n"[j == W - 1];
    }
    return 0;
}
