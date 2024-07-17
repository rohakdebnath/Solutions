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
    i64 N, K; cin >> N >> K;
    i64 ans = 0;
    if (K == 0){
        cout << N * N << '\n';
        return 0;
    }
    rep(i, K + 1, N + 1) ans += N / i * (i - K) + max<i64>(N % i - K + 1, 0);
    cout << ans << '\n';
    return 0;
}
