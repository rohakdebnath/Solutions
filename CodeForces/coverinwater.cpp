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
    int N; cin >> N;
    int maxstretch = 0;
    string s; cin >> s;
    int opens = count(all(s), '.');
    int stretch = 0;
    rep(1, N)
    {
        if (s[i] == '.' and s[i - 1] == '.') ++stretch;
        else stretch = 0;
        maxstretch = max(maxstretch, stretch);
    }
    if (opens) ++maxstretch;
    cout << (maxstretch >= 3 ? 2 : opens) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
