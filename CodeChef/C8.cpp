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

const i64 MOD = 998244353;

void solve()
{
    i64 N, K; cin >> N >> K;
    i64 poss = 1;
    i64 base = 2;
    i64 pow = (N - 1) * K;
    while (pow){
        if (pow & 1) poss = (poss * base) % MOD;
        base = (base * base) % MOD;
        pow /= 2;
    }
    cout << poss << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
