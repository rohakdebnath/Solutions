#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
void solve() {
    int n, k; cin >> n >> k; // n floors and k eggs
    int x = int(log2l(n)) + 1;
    if (k >= x) {
        cout << x << '\n';
        return;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; ++i) dp[i][1] = i;
    for (int i = 1; i <= k; ++i) dp[1][i] = 1;
    for (int e = 2; e <= k; ++e) {
        for (int f = 2; f <= n; ++f) {
            dp[f][e] = inf;
            int l = 1, r = f;
            while (r - l > 1) {
                int mid = l + (r - l) / 2;
                int b = dp[mid - 1][e - 1];  // Egg breaks
                int nb = dp[f - mid][e];  // Egg does not break
                if (b > nb) r = mid;
                else l = mid;
            }
            dp[f][e] = 1 + min(max(dp[l - 1][e - 1], dp[f - l][e]), max(dp[r - 1][e - 1], dp[f - r][e]));
        }
    }
    cout << dp[n][k] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}


//MAJOR DISCOVERY: The best position to drop an egg at every possible building height when we have atleast two eggs is at most the second unique element amongst the worst cases for every drop position, in other words the minimum value of worst case occurs at the first storey or the next storey at which the value is different from the worst value obtained from dropping the egg at the first storey
