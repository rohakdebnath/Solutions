#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    vector<int> a (3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; ++i) {
        sort(a.begin(), a.end());
        ++a[0];
    }
    
    cout << accumulate(a.begin(), a.end(), 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
