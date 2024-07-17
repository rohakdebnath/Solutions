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
    int n; cin >> n;
    string s; cin >> s;
    int ones = 0;
    rep(0, n)
    {
        ones += (s[i] == '1');
    }
    if (ones == n) cout << "No\n";
    else cout << "Yes\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
