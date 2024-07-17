#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>
const int MOD = 1e9 + 7;

int main()
{
    UNSYNC
    int N,M ; cin >> N >> M;
    vector<bool> A (N + 1, true);
    rep(0, M)
    {
        int a; cin >> a;
        A[a] = false;
    }
    VI prefs (N + 1); prefs[0] = 1;
    for(int i = 1; i <= N; ++i)
    {
        if (A[i - 1]) prefs[i] = (prefs[i] + prefs[i - 1]) % MOD;
        if (A[i - 2] and i > 1) prefs[i] = (prefs[i] + prefs[i - 2]) % MOD;
    }

    cout << prefs[N] << '\n';

    return 0;
}
