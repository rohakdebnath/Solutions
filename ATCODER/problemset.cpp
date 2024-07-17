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
    int N; cin >> N;
    unordered_map<int, int> Dfreq;
    rep(0, N)
    {
        int D; cin >> D;
        ++Dfreq[D];
    }
    int M; cin >> M;
    unordered_map<int, int> Tfreq;
    rep(0, M)
    {
        int T; cin >> T;
        ++Tfreq[T];
    }
    bool survive = true;
    for (auto [u, v]: Tfreq)
    {
        if (v > Dfreq[u])
        {
            survive = false;
            break;
        }
    }
    cout << (survive? "YES\n": "NO\n");
    return 0;
}
