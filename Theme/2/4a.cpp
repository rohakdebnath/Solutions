#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {  
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int j = find(a.begin(), a.end(), '1') - a.begin();
    if (j == n) {
        cout << (count(b.begin(), b.end(), '1') ? "NO\n" : "YES\n");
    } else {
        for (int i = 0; i < j; ++i) {
            if (b[i] == '1') {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
