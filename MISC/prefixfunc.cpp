#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s; 
    int n = s.size();

    vector<int> pi (n, 0);

    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    for (int i = 0; i < n; ++i) {
        cout << pi[i] << " \n"[i == n - 1];
    }

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    for (int i = n - 1; i >= 0; i--)
        ans[pi[i]] += ans[i + 1];
    for (int i = 0; i < n; i++)
        ans[i]++;

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
