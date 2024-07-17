#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int n; cin >> n;
    string s, f; cin >> s >> f;
    int o1ins = 0, o1inf = 0;
    rep(i, 0, n){
        if (s[i] == '0' and f[i] == '1') ++o1ins;
        if (s[i] == '1' and f[i] == '0') ++o1inf;
    }
    cout << max(o1inf, o1ins) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
