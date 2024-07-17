#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    string s; cin >> s;
    i64 ways = 0;
    rep(0, s.size() - 1)
    {
        if (s[i] == 'U') ways += s.size() - 1 - i;
        else ways += 2*(s.size() - 1 - i);
    }
    for(i64 i = s.size() - 1; i > 0; --i)
    {
        if (s[i] == 'D') ways += i;
        else ways += 2*i;
    }
    cout << ways << '\n';
    return 0;
}
