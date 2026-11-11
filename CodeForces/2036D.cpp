#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    int x = min(n, m) / 2;
    int ans = 0;
    
    for (int l = 0; l < x; l++) {
        string s;
        for(int j = l; j < m - l; j++) s += grid[l][j];
        for(int i = l + 1; i < n - l; i++) s += grid[i][m - l - 1];
        if (n - l - 1 != l) for(int j = m - l - 2; j >= l; j--) s += grid[n - l - 1][j];
        if (m - l - 1 != l) for(int i = n - l - 2; i > l; i--) s += grid[i][l];
        s += s.substr(0, 3);
        int cnt = 0;
        for(int i = 0; i + 3 < s.size(); i++) {
            if(s[i] == '1' and s[i + 1] == '5' and s[i + 2] == '4' and s[i + 3] == '3') {
                cnt++;
            }
        }
        ans += cnt;
    }
    
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
