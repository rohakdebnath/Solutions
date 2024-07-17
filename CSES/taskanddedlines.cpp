#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI starts (N), ends (N); rep(i, 0, N) cin >> starts[i] >> ends[i];
    sort(all(starts));
    VI pfs (N); partial_sum(all(starts), pfs.begin());
    i64 ind = -1;
    i64 ans = accumulate(all(pfs), 0LL, [&] (i64 s, i64 i) {
        ++ind;
        return s + ends[ind] - i;
    });
    cout << ans << '\n';
    return 0;
}
