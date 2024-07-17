#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 998244353;
i64 exp(i64 base, i64 pow){
    i64 res = 1;
    while (pow){
        if (pow & 1LL) res = res * base % MOD;
        base = base * base % MOD;
        pow /= 2;
    }
    return res;
}

int main()
{
    UNSYNC
    deque<pair<i64, i64>> f;
    i64 Q; cin >> Q;
    i64 cofx = 1;
    i64 cons = 0;
    while(Q--){
        i64 x; cin >> x;
        if (x == 0){
            i64 a, b; cin >> a >> b;
            f.push_back({a, b});
            cons = ((cofx + cons) * a % MOD + b) % MOD;
            cofx = cofx * a % MOD;
            cons = ((cons - cofx) % MOD + MOD) % MOD;
        } else if (x == 1){
            auto [u, v] = f.front();
            f.pop_front();
            cofx = cofx * exp(u, MOD - 2) % MOD;
            cons = ((cons - cofx * v) % MOD + MOD) % MOD;

        } else {
            i64 t; cin >> t;
            cout << (t * cofx % MOD + cons) % MOD << '\n';
        }
    }
    return 0;
}
