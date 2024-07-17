#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>


int main()
{
    UNSYNC
    int n; cin >> n;
    VI weights (n); rep(0, n) cin >> weights[i];
    VI prefw (n), suffw (n);

    prefw[0] = weights[0];
    for (int i = 1; i < n; ++i) prefw[i] = prefw[i - 1] + weights[i];
    suffw[n - 1] = weights[n - 1];
    for (int i = n - 2; i >= 0; --i) suffw[i] = suffw[i + 1] + weights[i];

    int diff = INT32_MAX;
    for (int i = 0; i < n - 1; ++i) diff = min(diff, abs(prefw[i] - suffw[i + 1]));

    cout << diff << '\n';
    return 0;
}
