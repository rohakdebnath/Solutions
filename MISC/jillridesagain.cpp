#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(int t) {
    int n; cin >> n; --n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int d = 0, s = 0, l = 1, r = 1, pl = 1, pr = 1;
    for (int i = 1; i <= n; ++i) {
        s += a[i - 1];
        r = i + 1;
        if (s < 0) { //drop the neg part of the segment and start new
            s = 0;
            l = i + 1;
        } else if (s > d or (s == d and r - l > pr - pl)) {
            d = s;
            pr = r;
            pl = l;
        }

    }
    if (d == 0) {
        cout << "Route " << t + 1 << " has no nice parts\n";
    } else {
        cout << "The nicest part of route " << t + 1 << " is between stops " << pl << " and " << pr << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        solve(i);        
    }
    return 0;
}
