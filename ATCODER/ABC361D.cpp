#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string test1 = s, test2 = t; sort(test1.begin(), test1.end()), sort(test2.begin(), test2.end());
    if (test1 != test2) {
        cout << "-1\n";
        return;
    }
    
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
