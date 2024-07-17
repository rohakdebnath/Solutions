#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    i64 N, M, X, Y, L; cin >> N >> M >> X >> Y >> L;
    i64 ans = ((Y - 1)/L + (M - Y)/L + 1) * ((X - 1)/L + (N - X)/L + 1);
    cout << ans << '\n';

}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
