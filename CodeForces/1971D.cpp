#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    string s; cin >> s;
    bitset<501> bit (s);
    if (bit.count() == 0 or bit.count() == s.size()){
        cout << "1\n";
    } else {
        int oi = -1, io = 0;
        rep(i, 1, int(s.size())){
            if (s[i] == '1' and s[i - 1] == '0') ++oi;
            else if (s[i] == '0' and s[i - 1] == '1') ++io;
        }
        int ans = 1 + max(0, oi) + io;
        cout << ans << '\n';
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
