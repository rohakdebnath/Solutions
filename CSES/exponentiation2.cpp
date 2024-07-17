#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1000000007;
const i64 MOD2 = 500000002; //phi(MOD - 1)

i64 exp(i64 base, i64 pow, i64 mod){
    i64 res = 1;
    while (pow){
        if (pow & 1) res = res * base % mod;
        base = base * base % mod;
        pow /= 2;
    }
    return res;
}

void solve()
{
    i64 A, B, C; cin >> A >> B >> C;
    cout << exp(A, exp(B, C % MOD2, MOD - 1), MOD) << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
