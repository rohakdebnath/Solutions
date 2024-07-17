#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i {ini}; i < x; ++i)
#define per(i, fin, x) for (i64 i {fin}; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
#define MOD sci(1e9 + 7)
int main()
{
    UNSYNC
    i64 N; cin >> N;
    string S; cin >> S;
    VI alpha (26);
    for (char c: S) ++alpha[c - 'a'];
    i64 ans = 1;
    for (i64 i: alpha) ans = (ans * (i + 1)) % MOD;
    cout << ans - 1 << '\n';
    return 0;
}
