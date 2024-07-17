#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MA = 1 << 9;
int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<vector<bool>> dp (MA, vector<bool> (MA, 0));
    rep(i, 0, MA) dp[0][i] = 1; //dp[l][m] means if we can make l using inc subseq with last element <= m;

    for (auto& a: A){
        if (a == 0) continue;
        rep(i, 0, MA){
            dp[i ^ a][a] = dp[i ^ a][a] || dp[i][a - 1];
            if (dp[i ^ a][a]){
                rep(j, a + 1, MA){
                    if (dp[a ^ i][j]) break;
                    dp[i ^ a][j] = 1;
                }
            }
        }
    }
    vector<int> ans;
    rep(i, 0, MA){
        if (dp[i][MA - 1]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    rep(i, 0, ans.size()) cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}
