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
        if (pow & 1) res = res * base % MOD;
        base = base * base % MOD;
        pow /= 2;
    }
    return res;
}
const i64 MX = 1000001;
int main()
{
    UNSYNC
    i64 N; cin >> N;
    i64 ans = 0;
    vector<i64> cnt (MX);
    vector<vector<i64>> data (N); 
    rep(i, 0, N){
        i64 k; cin >> k;
        rep(j, 0, k){
            i64 g; cin >> g;
            ++cnt[g];
            data[i].push_back(g);
        }
    }

    rep(i, 0, N){
        for (i64 j: data[i]){
            i64 base = (N * data[i].size() % MOD) * N % MOD;
            i64 imm = exp(base, MOD - 2) * cnt[j] % MOD;
            ans = (ans + imm) % MOD;
        }
    }
    cout << i64(ans) << '\n';
    return 0;
}
