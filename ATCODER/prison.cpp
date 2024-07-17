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
    int N, M; cin >> N >> M;
    int l = 0, r = INT32_MAX;

    rep(0, M)
    {
        int L, R; cin >> L >> R;
        l = max(l, L);
        r = min(r, R);
    }
    cout << (r >= l ? r - l + 1 : 0) << '\n';
    return 0;
}
