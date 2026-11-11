#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    // vector<vector<int>> dp (n, vector<int> (2)); //dp[i][j] = minimum number of operations required to make prefix i alternating with j operations of type 1
    if (n % 2) {
        vector<vector<int>> fo (n, vector<int> (26)), fe (n, vector<int> (26));
        for (int i = 0; i < n; ++i) {
            fe[i] = i - 1 >= 0 ? fe[i - 1] : vector<int> (26);
            fo[i] = i - 1 >= 0 ? fo[i - 1] : vector<int> (26);
            if (i % 2) {
                ++fe[i][s[i] - 'a'];
            } else {
                ++fo[i][s[i] - 'a'];
            }
        }
        int t = n - *max_element(fe[n - 1].begin(), fe[n - 1].end());
        auto f = fo[n - 1];
        --fo[n - 1][s[0] - 'a'];
        t -= *max_element(fo[n - 1].begin(), fo[n - 1].end());
        ++fo[n - 1][s[0] - 'a'];
        int ans = t;
        --fo[n - 1][s[n - 1] - 'a'];
        t = n - *max_element(fo[n - 1].begin(), fo[n - 1].end()) - *max_element(fe[n - 1].begin(), fe[n - 1].end());
        ++fo[n - 1][s[n - 1] - 'a'];
        ans = min(ans, t);

        for (int i = 1; i < n - 1; ++i) {
            auto tfo = fo[i - 1];
            auto tfe = fe[i - 1];
            auto x = fe[n - 1];
            for (int j = 0; j < 26; ++j) {
                x[j] -= fe[i][j];
            }
            auto y = fo[n - 1];
            for (int j = 0; j < 26; ++j) {
                y[j] -= fo[i][j];
            }
            for (int j = 0; j < 26; ++j) {
                tfo[j] += x[j];
                tfe[j] += y[j];
            }
            t = n - *max_element(tfo.begin(), tfo.end()) - *max_element(tfe.begin(), tfe.end());
            ans = min(ans, t);
        }
        cout << ans << '\n';
    } else {
        int ans = 0;
        vector<int> fo (26), fe (26);
        for (int i = 0; i < n; ++i) {
            if (i % 2) ++fe[s[i] - 'a'];
            else ++fo[s[i] - 'a'];
        }
        ans += n - *max_element(fe.begin(), fe.end()) - *max_element(fo.begin(), fo.end());
        cout << ans << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
