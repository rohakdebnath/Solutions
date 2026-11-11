#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;//for deleting an element, instead of m.erase(m.find(key)) or m.erase(key) use m.erase(m.upper_bound(key)), because less_equal reverses the roles of upper and lower bound
template<class T> using o_multiset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    o_multiset<int> s;

    int ans = 1e9;
    for (int i = n - 1; i >= 0; --i) {
        s.insert(a[i]);
        ans = min<int>(ans, n - s.order_of_key(a[i] + 1));
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
