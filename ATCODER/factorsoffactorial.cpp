#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1e9 + 7;

int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<i64> facts (1001, 1);
    rep(i, 1, N + 1){
        i64 n = i;
        for (i64 j = 2; j * j <= n; j++){
            while (n % j == 0){
                ++facts[j];
                n /= j;
            }
        }
        if (n > 1) ++facts[n];
    }

    i64 ans = accumulate(all(facts), 1LL, [&] (i64 M, i64 i) {
        return (M * i) % MOD;
    });

    cout << ans << '\n';
    return 0;
}
