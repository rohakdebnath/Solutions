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
    VI a (s.size() + 1);
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '<') a[i + 1] = max(a[i + 1], a[i] + 1);
    }
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '>') a[i] = max(a[i + 1] + 1, a[i]);
    }
    cout << accumulate(all(a), 0) << '\n';
    return 0;
}
