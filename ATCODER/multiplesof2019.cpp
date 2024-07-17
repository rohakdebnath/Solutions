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
#define MOD 2019

int main()
{
    UNSYNC
    string S; cin >> S;

    VI occr (2019);
    int suf = 0;
    int pot = 1;
    ++occr[suf];
    i64 ans = 0;
    per(i, S.size() - 1, 0)
    {
        suf = (suf + (S[i] - '0')*pot) % MOD;
        pot = (pot*10) % MOD;
        ans += occr[suf];
        ++occr[suf];
    }
    cout << ans << '\n';
    return 0;
}
