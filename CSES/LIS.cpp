#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);

int main()
{
    UNSYNC
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n + 1, 1e9); dp[0] = -1e9;
    for(int i = 0; i < n; ++i) {
        int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[l] = a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[i] < 1e9) ans = i;
    }
    cout << ans << '\n';
    return 0;
}
