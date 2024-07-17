#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    string s; cin >> s;
    for (int i = 0 ; i < 8; ++i)
    {
        if (i + 1 != s[1] - '0')
        cout << s[0] << i + 1 << '\n';
    }
    for (int i = 0; i < 8; ++i)
    {
        if (i != s[0] - 'a')
        cout << char('a' + i) << s[1] << '\n';
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
