#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n; 
    string s; cin >> s;
    int x = 0; while (x < n and s[x] == 'B') ++x;
    int y = n - 1; while (y >= 0 and s[y] == 'A') --y;
    cout << max(y - x, 0) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

