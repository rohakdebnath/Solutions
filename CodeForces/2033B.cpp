#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for(auto &row : m) {
        for(auto &val : row) {
            cin >> val;
        }
    }
    
    int ans = 0;
    vector<int> dia(2 * n - 1, inf);
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int d = i - j;
            int x = d + (n - 1);
            dia[x] = min(dia[x], m[i][j]);
        }
    }
    
    for(int d = 0; d < 2 * n - 1; ++d){
        if (dia[d] < 0){
            ans += abs(dia[d]);
        }
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
