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
    i64 N; cin >> N;
    vector<i64> lens (N); rep(0, N) cin >> lens[i];
    i64 l = 0, r = accumulate(all(lens), 0LL);
    i64 minDiff = r;
    for (i64 i = 0; i < N; ++i)
    {
        l += lens[i];
        r -= lens[i];
        minDiff = min(minDiff, abs(l - r));
    }
    cout << minDiff << '\n';

    return 0;
}
