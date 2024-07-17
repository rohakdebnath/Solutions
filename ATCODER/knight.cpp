#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1e9 + 7;
i64 exp(i64 base, i64 pow){
    i64 res = 1;
    while (pow){
        if (pow & 1) res = res * base % MOD;
        base = base * base % MOD;
        pow /= 2;
    }
    return res;
}

i64 nCr(i64 n, i64 k) {
    if (k > n or k < 0) return 0;
    if (k > n - k) k = n - k;
    i64 numerator = 1;
    i64 denominator = 1;
    for (i64 i = 0; i < k; ++i) {
        numerator = (numerator * (n - i)) % MOD;
        denominator = (denominator * (i + 1)) % MOD;
    }
    return (numerator * exp(denominator, MOD - 2)) % MOD;
}
int main()
{
    UNSYNC
    i64 X, Y; cin >> X >> Y;
    if ((X + Y) % 3){
        cout << "0\n";
        return 0;
    }
    i64 lvl = (X + Y) / 3;
    i64 ans = nCr(lvl, X - lvl);
    cout << ans << '\n';
    return 0;
}
