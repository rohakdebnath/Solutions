#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    string s; cin >> s;
    VI a (s.size() + 1);
    for (i64 i = 0; i < s.size(); ++i)
    {
        if (s[i] == '<') a[i + 1] = max(a[i + 1], a[i] + 1);
    }
    for (i64 i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '>') a[i] = max(a[i + 1] + 1, a[i]);
    }
    cout << accumulate(all(a), 0LL) << '\n';
    return 0;
}
