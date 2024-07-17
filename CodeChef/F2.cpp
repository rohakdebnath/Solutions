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

void solve()
{
    i64 N, M; cin >> N >> M;
    VI A (N); rep(i, 0, N) cin >> A[i];
    i64 maxel = *max_element(all(A));
    VI newA (N); rep(i, 0, N) newA[i] = maxel - A[i];
    i64 nmxl = *max_element(all(newA));
    if (nmxl == 0)
    {
        cout << "0\n";
        return;
    }
    i64 ans = max(nmxl, (accumulate(all(newA), 0LL) - 1)/M + 1);
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
