#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
#define MOD sci(1e9 + 7)

void solve()
{
    i64 N; cin >> N;
    string s; cin >> s;
    VI alpha (26, 1);
    for(char c: s) ++alpha[c - 'a'];
    i64 prod = alpha[0];
    rep(1, 26)
    {
        prod = (prod*alpha[i]) % MOD;
    }
    cout << prod - 1 << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
