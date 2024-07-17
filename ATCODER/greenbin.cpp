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
    i64 N; cin >> N;
    unordered_map<string, i64> mp;

    rep(0, N)
    {
        string s; cin >> s;
        sort(all(s));
        ++mp[s];
    }

    i64 combos = 0;
    for (auto [u, v] : mp)
    {
        if (v >= 2) combos += v * (v - 1) / 2;
    }

    cout << combos << '\n';
    return 0;
}
