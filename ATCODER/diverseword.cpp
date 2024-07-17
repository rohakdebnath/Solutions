#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    string S; cin >> S;
    if (S.size() < 26)
    {
        VI alpha (26);
        for (char c: S) ++alpha[c - 'a'];
        rep(i, 0, 26) if (alpha[i] == 0)
        {
            cout << S << static_cast<char>('a' + i) << '\n';
            return 0;
        }
    }
    int pos = 0;
    rep(i, 1, 26)
    {
        if (S[i] > S[i - 1]) pos = i;
    }
    if (pos == 0) {cout << "-1\n"; return 0;}
    string ans = S.substr(0, pos - 1);
    VI alpha (26);
    for (char c: ans) ++alpha[c - 'a'];
    rep(i, 0, 26) if (alpha[i] == 0 and 'a' + i > S[pos - 1])
    {
        cout << ans << static_cast<char>('a' + i) << '\n';
        return 0;
    }
    return 0;
}
