// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// const int inf = 1e9;
// void solve() {
//     int s, n; cin >> s >> n;
//     vector<int> a (n + 2); for (int i = 0; i < n; ++i) cin >> a[i + 1];
//     a[n + 1] = s;
//     sort(a.begin(), a.end());
//     vector<vector<int>> dp (n + 2, vector<int> (n + 2)); //dp[i][j] = min cost to perform cuts in the subarray i..j

//     for (int i = n; i >= 1; --i) {
//         for (int j = i; j <= n; ++j) {
//             dp[i][j] = inf;
//             for (int k = i; k <= j; ++k) {
//                 dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[j + 1] - a[i - 1]);
//             }
//         }
//     }
//     cout << dp[1][n] << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int T; cin >> T;
//     while(T--) solve();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;

void solve() {
    int n; cin >> n;
    
    vector<int> a(n + 2, 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    //dp[i][j] = max coins gained while reviving segment i..j
    function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = -inf;
        for (int k = i; k <= j; ++k) {
            int cost = a[i - 1] * a[k] * a[j + 1] + dfs(i, k - 1) + dfs(k + 1, j);
            res = max(res, cost);
        }
        return dp[i][j] = res;
    };
    
    cout << dfs(1, n) << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

