#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i {ini}; i < x; ++i)
#define per(i, fin, x) for (i64 i {fin}; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N, K; cin >> N >> K;
    map<i64, i64> freq;
    rep(i, 0, N)
    {
        i64 a, b; cin >> a >> b;
        freq[a] += b;
    }
    for(auto [u, v]: freq)
    {
        if (K <= v)
        {
            cout << u << '\n';
            return 0;
        }
        K -= v;
    }
    return 0;
}
