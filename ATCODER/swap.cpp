#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 T = 30 * 31 / 2;
int main()
{
    UNSYNC
    string s; cin >> s;
    i64 N = s.size();
    i64 K; cin >> K;
    vector<i64> count (3);
    vector<vector<i64>> pos (3);
    vector<vector<i64>> pfx (3, vector<i64> (N));

    rep(i, 0, N){
        pfx[0][i] = (i > 0 ? pfx[0][i - 1] : 0) + (s[i] == 'K');
        pfx[1][i] = (i > 0 ? pfx[1][i - 1] : 0) + (s[i] == 'E');
        pfx[2][i] = (i > 0 ? pfx[2][i - 1] : 0) + (s[i] == 'Y');

        if (s[i] == 'K'){
            ++count[0];
            pos[0].push_back(i);
        } else if (s[i] == 'E'){
            ++count[1];
            pos[1].push_back(i);
        } else {
            ++count[2];
            pos[2].push_back(i);
        }
    }

    vector<vector<vector<vector<i64>>>> dp (T + 1, vector<vector<vector<i64>>> (count[0] + 1, vector<vector<i64>> (count[1] + 1, vector<i64> (count[2] + 1, 0))));
    dp[0][0][0][0] = 1;
    i64 ans = 0;
    rep(k, 0, count[0] + 1){
        rep(e, 0, count[1] + 1){
            rep(y, 0, count[2] + 1){
                rep(c, 0, T + 1){
                    if (count[0] - k > 0){ //this condition checks if one more k can be added in the string's end
                        i64 next = pos[0][k];
                        i64 cost = max(pfx[1][next] - e, 0LL) + max(pfx[2][next] - y, 0LL);
                        if (cost + c <= T) dp[cost + c][k + 1][e][y] += dp[c][k][e][y];
                    }
                    if (count[1] - e > 0){
                        i64 next = pos[1][e];
                        i64 cost = max(pfx[0][next] - k, 0LL) + max(pfx[2][next] - y, 0LL);
                        if (cost + c <= T) dp[cost + c][k][e + 1][y] += dp[c][k][e][y];
                    }
                    if (count[2] - y > 0){
                        i64 next = pos[2][y];
                        i64 cost = max(pfx[1][next] - e, 0LL) + max(pfx[0][next] - k, 0LL);
                        if (cost + c <= T) dp[cost + c][k][e][y + 1] += dp[c][k][e][y];
                    }
                    if (k == count[0] and e == count[1] and y == count[2] and c <= K){
                        ans += dp[c][k][e][y];
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
