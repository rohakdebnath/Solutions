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
    int N, K; cin >> N >> K;
    VI h (N); rep(0, N) cin >> h[i];
    sort(all(h));
    int minDiff = INT32_MAX;
    for (int i = 0; i < N - K + 1; ++i)
    {
        minDiff = min(minDiff, h[i + K - 1] - h[i]);
    }
    cout << minDiff << '\n';
    return 0;
}
