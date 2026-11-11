#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ost;

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    ost tree;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        tree.insert(x);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
