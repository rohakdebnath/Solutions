#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s, r; cin >> s >> r;
    
    array<int, 2> c;
    c[0] = count(r.begin(), r.end(), '0');
    c[1] = count(s.begin(), s.end(), '1');
    
    cout << ((c[0] == c[1] and r.back() == '0') or (c[0] == (c[1] - 1) and r.back() == '1') ? "YES\n": "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
