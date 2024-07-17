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
    //longest seq of decreasing elements
    int N; cin >> N;
    VI H (N); rep(0, N) cin >> H[i];

    VI dp (N);
    for (int i = N - 2; i >= 0; --i)
    {
        if (H[i] >= H[i + 1]) dp[i] += dp[i + 1] + 1;
    }

    cout << *max_element(all(dp)) << '\n';
    return 0;
}
