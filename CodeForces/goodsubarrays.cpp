#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 N; cin >> N;
    string s; cin >> s;
    VI pref (N); pref[0] = s[0] - '0';
    rep(i, 1, N) pref[i] = pref[i - 1] + s[i] - '0';
    unordered_map<i64, i64> freq;
    ++freq[1];
    i64 ans = 0;
    rep(i, 0, N)
    {
        ans += freq[pref[i] - i];
        ++freq[pref[i] - i];
    }
    cout << ans << '\n';

}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
