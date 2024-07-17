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

int main()
{
    UNSYNC
    string S; cin >> S;
    i64 K; cin >> K;
    i64 N = S.size();
    i64 i = 1;
    while (S[i] == S[i - 1]) ++i;
    i64 j = N - 2;
    while (S[j] == S[j + 1]) --j;

    if (i >= j)
    {
        cout << S.size()*K/2 << '\n';
        return 0;
    }

    string cn = S.substr(j + 1, N - 1 - j) + S.substr(0, i);
    i64 cncg = 0;
    rep(x, 1, cn.size())
    {
        if (cn[x] == cn[x - 1])
        {
            ++cncg;
            ++x;
        }
    }
    i64 y = 0;
    rep(x, i + 1, j + 1)
    {
        if (S[x] == S[x - 1])
        {
            ++x;
            ++y;
        }
    }
    i64 changes = cncg* (K - 1) + i/2 + (N - 1 - j)/2 + K*y;
    cout << changes << '\n';
    return 0;
}
