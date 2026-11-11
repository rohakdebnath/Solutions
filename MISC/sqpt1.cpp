#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> getRefinedEntries(vector<int> a) {
    int n = a.size();
    vector<int> pos(n + 1), used(n);
    for (int i = 0; i < n; ++i) pos[a[i]] = i;

    for (int x = 1; x <= n; ++x) {
        int j = pos[x];
        while (j > 0 and !used[j - 1] and a[j - 1] > x) {
            used[j - 1] = 1;
            swap(a[j - 1], a[j]);
            pos[a[j]] = j;
            pos[x] = --j;
        }
    }
    return a;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto ans = getRefinedEntries(a);
    for (int x: ans) cout << x << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
