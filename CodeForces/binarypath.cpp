#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve() {
    int N; cin >> N;
    vector<vector<int>> g (2, vector<int> (N));
    rep(i, 0, 2){
        rep(j, 0, N){
            char c; cin >> c;
            g[i][j] = c == '1';
        }
    }
    string s = ""; s += '0' + g[0][0];
    int i = 0, j = 0, way = 1;
    while (i < 1 and j < N - 1){
        if (g[i][j + 1] == g[i + 1][j]){
            s += '0' + g[i + 1][j];
            ++j;
            way += 1;
        } else if (g[i][j + 1]){
            s += '0' + g[i + 1][j];
            ++i;
        } else {
            s += '0' + g[i][j + 1];
            ++j;
            way = 1;
        }
    }
    rep(t, j + 1, N){
        s += '0' + g[i][t];
    }
    if (!i) s += '0' + g[1][N - 1];
    cout << s << '\n' << way << '\n';

}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
