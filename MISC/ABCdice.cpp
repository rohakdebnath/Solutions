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
    int A, B, C; cin >> A >> B >> C;
    vector<vector<int>> ans (A + 1, vector<int> (C + 1));
    ans[0][0] = 1;

    for (int i = 1; i <= A; i++) {
        for (int j = i; j <= C; j++) {
            ans[i][j] = (ans[i][j - 1] + ans[i - 1][j - 1]) % MOD;
            if (j > B) ans[i][j] = (ans[i][j] - ans[i - 1][j - B - 1] + MOD) % MOD;
        }
    }
    cout << ans[A][C] << '\n';
    return 0;
}
