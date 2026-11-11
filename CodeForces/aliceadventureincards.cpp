#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const array<char, 3> c {'q', 'k', 'j'};
void solve() {
    int n; cin >> n;
    array<vector<int>, 3> a;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x; --x;
            a[i].push_back(x);
        }
    }
    for (int t = 0; t < 3; ++t) {
        vector<int> iot (n); iota(iot.begin(), iot.end(), 0);
        sort(iot.begin(), iot.end(), [&] (int i, int j) {return a[t][j] < a[t][i];});
        a[t] = iot;
    }
    
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
