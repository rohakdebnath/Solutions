#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int dp[201][201][201]; 
void prec()
{
    rep(i, 0, 201){
        rep(j, 0, 201){
            rep(k, 0, 201){
                int prev = 0;
                if (i) prev = max(prev, dp[i - 1][j][k]);
                if (j) prev = max(prev, dp[i][j - 1][k]);
                if (k) prev = max(prev, dp[i][j][k - 1]);
                dp[i][j][k] = prev;
                int xr = ((i & 1) * 1) ^ ((j & 1) * 2) ^ ((k & 1) * 3);
                if (xr == 0 && (i or j or k))  ++dp[i][j][k];
            }
        }
    }

}

void solve(){
    vector<int> B (4); rep(i, 0, 4) cin >> B[i];
    cout << dp[B[0]][B[1]][B[2]] + B[3]/2 << '\n';
}
int main()
{
    UNSYNC
    memset(dp, 0, sizeof(dp));
    prec();
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
