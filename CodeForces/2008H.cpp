#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> p (n + 1); //p[i] = count of numbers in the range [0 to i]
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++p[x];
    }
    partial_sum(p.begin(), p.end(), p.begin());
    vector<int> ans (n + 1);
    for (int x = 0; x <= n; ++x) {
        auto check = [&] (int m) { //counts how many element % x is <= m (m is always chosen to be less than x)
            //returns true if count of elements with (a_i % x <= m) >= n / 2 + 1; 
            //for this need to precalc the number of elements in the range [ix, ix + m] for all i 
            int count = 0;
            for (int i = 0; i * x <= n; ++i) {
                count += p[min(i * x + m, n)] - (i * x - 1 >= 0 ? p[i * x - 1]: 0);
            }
            return count >= n / 2 + 1;
        };
        int l = -1, r = x; //condition if median can be <= m, => atleast half the elements can be <= m
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (check(m)) r = m; //checks if m can be median,
            else l = m;
        }
        ans[x] = r;
    }
    while (q--) {
        int x; cin >> x;
        cout << ans[x] << " \n"[q == 0];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
