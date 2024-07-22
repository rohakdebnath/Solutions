#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sort(s.begin(), s.end());
    int ans = 0;
    do {
        bool srv = 1; //no palindromes or not
        for (int i = 0; i + k < n; ++i) {
            bool pal = 1;
            for (int j = 0; j < k / 2; ++j) {
                if (s[i + j] != s[i + k - 1 - j]) {
                    pal = 0;
                    break;
                }
            }
            if (pal) {
                srv = 0;
                break;
            }
        }
        ans += srv;
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
