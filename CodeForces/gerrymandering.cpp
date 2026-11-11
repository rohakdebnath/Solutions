#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    i64 n; cin >> n;
    
    vector<vector<char>> a(n, vector<char>(2));
    for (i64 j = 0; j < 2; ++j) {
        for (i64 i = 0; i < n; ++i) {
            cin >> a[i][j];
        }
    }

    vector dp(n + 1, vector<i64>(7)); // dp[7][i] = max alvaro points when ending at city j with a particular shape 
    dp[1] = vector<i64>(7, -inf);
    dp[3][2] = dp[3][3] = dp[3][5] = dp[3][6] = dp[2][0] = dp[2][1] = dp[2][4] = dp[2][5] = dp[2][6] = -inf;
    
    auto count = [&] (i64 t, i64 i) -> i64 {
        i64 cnt = 0, ans = 0;
        switch(t) {
            case 0:
                cnt = (a[i][0] == 'A') + (a[i][1] == 'A') + (a[i - 1][0] == 'A');
                ans += cnt >= 2;
                break;
            case 1:
                cnt = (a[i][0] == 'A') + (a[i][1] == 'A') + (a[i - 1][1] == 'A');
                ans += cnt >= 2;
                break;
            case 2:
                cnt = (a[i][0] == 'A') + (a[i - 1][0] == 'A') + (a[i - 1][1] == 'A');
                ans += cnt >= 2;
                break;
            case 3:
                cnt = (a[i][1] == 'A') + (a[i - 1][0] == 'A') + (a[i - 1][1] == 'A');
                ans += cnt >= 2;
                break;
            case 4:
                cnt = (a[i][0] == 'A') + (a[i - 1][0] == 'A') + (a[i - 2][0] == 'A');
                ans += cnt >= 2;
                cnt = (a[i][1] == 'A') + (a[i - 1][1] == 'A') + (a[i - 2][1] == 'A');
                ans += cnt >= 2;
                break;
            case 5:
                cnt = (a[i][1] == 'A') + (a[i - 1][1] == 'A') + (a[i - 2][1] == 'A');
                ans += cnt >= 2;
                cnt = (a[i - 1][0] == 'A') + (a[i - 2][0] == 'A') + (a[i - 3][0] == 'A');
                ans += cnt >= 2;
                break;
            case 6:
                cnt = (a[i][0] == 'A') + (a[i - 1][0] == 'A') + (a[i - 2][0] == 'A');
                ans += cnt >= 2;
                cnt = (a[i - 1][1] == 'A') + (a[i - 2][1] == 'A') + (a[i - 3][1] == 'A');
                ans += cnt >= 2;
                break;
        }
        return ans;
    };

    for (i64 i = 1; i < n; ++i) {
        for (i64 j = 0; j < 7; ++j) {
            if (i >= 1) {
                switch (j) {
                    case 0:
                        dp[i + 1][0] = max({dp[i + 1][0], dp[i][3] + count(0, i), dp[i][5] + count(0, i)});
                        break;
                    case 1:
                        dp[i + 1][1] = max({dp[i + 1][1], dp[i][2] + count(1, i), dp[i][6] + count(1, i)});
                        break;
                    case 2:
                        dp[i + 1][2] = max({dp[i + 1][2], dp[i - 1][0] + count(2, i), dp[i - 1][1] + count(2, i), dp[i - 1][4] + count(2, i)});
                        break;
                    case 3:
                        dp[i + 1][3] = max({dp[i + 1][3], dp[i - 1][0] + count(3, i), dp[i - 1][1] + count(3, i), dp[i - 1][4] + count(3, i)});
                        break;
                }
            }
            if (i >= 2) {
                switch (j) {
                    case 0:
                        dp[i + 1][0] = max({dp[i + 1][0], dp[i][3] + count(0, i), dp[i][5] + count(0, i)});
                        break;
                    case 1:
                        dp[i + 1][1] = max({dp[i + 1][1], dp[i][2] + count(1, i), dp[i][6] + count(1, i)});
                        break;
                    case 2:
                        dp[i + 1][2] = max({dp[i + 1][2], dp[i - 1][0] + count(2, i), dp[i - 1][1] + count(2, i), dp[i - 1][4] + count(2, i)});
                        break;
                    case 3:
                        dp[i + 1][3] = max({dp[i + 1][3], dp[i - 1][0] + count(3, i), dp[i - 1][1] + count(3, i), dp[i - 1][4] + count(3, i)});
                        break;
                    case 4:
                        dp[i + 1][4] = max({dp[i + 1][4], dp[i - 2][4] + count(4, i), dp[i - 2][0] + count(4, i), dp[i - 2][1] + count(4, i)});
                        break;
                }
            }
            if (i >= 3) {
                switch (j) {
                    case 0:
                        dp[i + 1][0] = max({dp[i + 1][0], dp[i][3] + count(0, i), dp[i][5] + count(0, i)});
                        break;
                    case 1:
                        dp[i + 1][1] = max({dp[i + 1][1], dp[i][2] + count(1, i), dp[i][6] + count(1, i)});
                        break;
                    case 2:
                        dp[i + 1][2] = max({dp[i + 1][2], dp[i - 1][0] + count(2, i), dp[i - 1][1] + count(2, i), dp[i - 1][4] + count(2, i)});
                        break;
                    case 3:
                        dp[i + 1][3] = max({dp[i + 1][3], dp[i - 1][0] + count(3, i), dp[i - 1][1] + count(3, i), dp[i - 1][4] + count(3, i)});
                        break;
                    case 4:
                        dp[i + 1][4] = max({dp[i + 1][4], dp[i - 2][4] + count(4, i), dp[i - 2][0] + count(4, i), dp[i - 2][1] + count(4, i)});
                        break;
                    case 5:
                        dp[i + 1][5] = max({dp[i + 1][5], dp[i - 2][5] + count(5, i), dp[i - 2][3] + count(5, i)});
                        break;
                    case 6:
                        dp[i + 1][6] = max({dp[i + 1][6], dp[i - 2][6] + count(6, i), dp[i - 2][2] + count(6, i)});
                        break;
                }
            }
        }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][4]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
