#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N, a, b; cin >> N >> a >> b;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    i64 ans = 0;
    rep(i, 1, N){
        ans += min((A[i] - A[i - 1]) * a, b);
    }
    cout << ans << '\n';
    return 0;
}
