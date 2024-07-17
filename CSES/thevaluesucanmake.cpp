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
    int N, K; cin >> N >> K;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<vector<int>> dp (K + 1, vector<int> (K + 1)); //dp[j][x] means if we are making j, and x can be made while eliminating some elements that we used while making j, then dp[j][x] will be true
    dp[0][0] = 1;
    rep(i, 0, N){
        per(j, K, 0){
            rep(x, 0, K + 1){
                if (j - A[i] >= 0) dp[j][x] |= dp[j - A[i]][x];
                if (j - A[i] >= 0 and x - A[i] >= 0) dp[j][x] |= dp[j - A[i]][x - A[i]] ;
            }
        }
    }

    vector<int> ans;
    rep(i, 0, K + 1){
        if (dp[K][i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    rep(i, 0, ans.size()){
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
