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
    int n; cin >> n;
    VVI mat (n, VI (n));
    rep(i, 0, n){
        rep(j, 0, n){
            char c; cin >> c;
            mat[i][j] = c;
        }
    }
    bool survive = true;
    int i = 0;
    int c = mat[0][0];
    while (i < n/2 + 1){
        if (!(mat[i][i] == mat[i][n - 1 - i] and mat[n - 1 - i][n - 1 - i] == mat[n - 1 - 1][i] and mat[n - 1 - 1][i] == mat[i][i] and mat[i][i] == c)){
            survive = false;
            break;
        }
        ++i;
    }
    cout << (survive ? "Yes\n": "No\n");
    return 0;
}
