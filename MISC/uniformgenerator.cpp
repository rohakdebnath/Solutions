#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int STEP, MOD; cin >> STEP >> MOD;
    int count = 1;
    int seed = 0;
    VI occ (MOD);
    ++occ[seed];
    rep(i, 1, MOD)
    {
        seed = (seed + STEP) % MOD;
        if (!occ[seed]) ++occ[seed], ++count;
    }
    cout << (count == MOD ? "good choice" : "bad choice") << '\n';
    return 0;
}
