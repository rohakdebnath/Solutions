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
    int N; cin >> N;
    VI B (N + 1); rep(1, N) cin >> B[i];
    B[0] = INT32_MAX;
    B[N] = INT32_MAX;

    int ans = 0;
    for (int i = 1; i < N + 1; ++i)
    {
        ans += min(B[i], B[i - 1]);
    }

    cout << ans << '\n';
    return 0;
}
