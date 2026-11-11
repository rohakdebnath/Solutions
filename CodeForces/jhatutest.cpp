#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    priority_queue<i64> pq;
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
        i64 x; cin >> x;
        s += x;
        pq.push(x);
    }
    if 
    int x; cin >> x;
    i64 ans = 0;
    while (true) {
        vector<i64> a (x);
        for (int i = 0; i < x; ++i) {
            a[x - i - 1] = pq.top();
            pq.pop();
        }
        if (a[0] == 0) break;
        ans += a[0];
        for (int i = 0; i < x; ++i) {
            pq.push(a[i] - a[0]);
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
