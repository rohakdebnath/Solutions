#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector<int> f(26, 0);
    int j = 0;
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        while (j < n) {
            ++f[s[j++] - 'A'];
            if (j - i - *max_element(f.begin(), f.end()) > k) {
                --f[s[--j] - 'A'];
                break;
            }
        }
        ans = max(ans, j - i);
        --f[s[i] - 'A'];
    }
    
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
