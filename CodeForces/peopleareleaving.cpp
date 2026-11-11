#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> next (n);
    iota(next.begin(), next.end(), 0);

    function<int(int)> march = [&] (int x) {
        if(x == n) return n;
        if (x != next[x]) next[x] = march(next[x]); 
        return next[x];
    };
    while (k--) {
        char c; cin >> c;
        int x; cin >> x;
        --x;
        if (c == '?') {
            int pos = march(x);
            cout << (pos == n ? -1 : pos + 1) << '\n';
        } else {
            next[x] = march(x + 1);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
