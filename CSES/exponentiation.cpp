#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1e9 + 7;
i64 binexp(i64 base, i64 pow){
    i64 res = 1;
    while (pow){
        if (pow & 1) res = res * base % MOD;
        base = base * base % MOD;
        pow /= 2;
    }
    return res;
}
void solve()
{
    i64 A, B; cin >> A >> B;
    cout << binexp(A, B) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
