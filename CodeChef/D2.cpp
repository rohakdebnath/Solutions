#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int N; cin >> N;
    int ones = 0;
    int zeros = 0;
    rep(i, 0, N)
    {
        int a; cin >> a;
        if (a == 0) ++zeros;
        else ++ones;
    }
    cout << min(ones, zeros) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
