#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int m = *max_element(a.begin(), a.end());
    vector<int> comp;
    for (int i = 0; i < n; ++i) {
        int d = (m - a[i]) % (2 * k);
        comp.push_back(m - d);
        comp.push_back(m - d + k);
        comp.push_back(m - d + 2 * k);
        comp.push_back(m - d + 3 * k);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    auto cmp = [&] (int x) {
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    };
    vector<int> p (comp.size());
    for (int i = 0; i < n; ++i) {
        int d = (m - a[i]) % (2 * k);
        ++p[cmp(m - d)];
        --p[cmp(m - d + k)];
        ++p[cmp(m - d + 2 * k)];
        --p[cmp(m - d + 3 * k)];
    }
    partial_sum(p.begin(), p.end(), p.begin());
    int x = find(p.begin(), p.end(), n) - p.begin();
    if (x == p.size()) cout << "-1\n";
    else cout << comp[x] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
