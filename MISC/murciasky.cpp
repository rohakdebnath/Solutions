#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(int i) {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> w (n); for (int i = 0; i < n; ++i) cin >> w[i];

    vector<int> lis (n), lds (n); //sum of the maximum weight you can get from a lis (lds)
    for (int i = 0; i < n; ++i) {
        lis[i] = w[i];
        lds[i] = w[i];
        for (int j = i - 1; j >= 0; --j) {
            if (a[i] > a[j]) lis[i] = max(lis[i], lis[j] + w[i]);
            if (a[i] < a[j]) lds[i] = max(lds[i], lds[j] + w[i]);
        }
    }
    int mlis = *max_element(lis.begin(), lis.end()), mlds = *max_element(lds.begin(), lds.end());
    cout << "Case " << i + 1 << ". ";
    if (mlis >= mlds) {
        cout << "Increasing (" << mlis << "). Decreasing (" << mlds << ").\n";
    } else {
        cout << "Decreasing (" << mlds << "). Increasing (" << mlis << ").\n";
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
