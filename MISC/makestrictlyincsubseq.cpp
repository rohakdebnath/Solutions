//i call this a greedy not a dp. there is no overlapping subproblems, only a single precalculted subproblem for every problem hence not dp
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<int> ans (n + 1); //ans[i] = operations required to make the prefix i non decreasing
    vector<int> sum (n + 1); //sum[i] = sum of the merging ending at index i st this merge makes the array non decreasing 

    for (int i = 0; i < n; ++i) {
        int j = i - 1;
        sum[i] = a[i];
        while (j >= 0 and sum[i] < sum[j]) {
            sum[i] += a[j--];
        }
        ans[i + 1] = ans[j + 1] + i - j - 1;
    }

    cout << ans[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
