#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<int> a;
    int x; 
    while (cin >> x) a.push_back(x);
    int n = a.size();
    vector<int> dp (n + 1, 1e9); dp[0] = -1e9;
    vector<int> d (n, -1), p (n);
    for(int i = 0; i < n; ++i) {
        int l = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[l] = a[i];
        d[l] = i;
        p[i] = d[l - 1];
    }
    int ans = n; while (dp[ans] == 1e9) --ans;
    int b = d[ans];
    vector<int> s;
    while (b != -1) {
        s.push_back(a[b]);
        b = p[b];
    }
    reverse(s.begin(), s.end());
    cout << ans << "\n-\n";
    for (int i = 0; i < ans; ++i) {
        cout << s[i] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while(T--) solve();
    return 0;
}
