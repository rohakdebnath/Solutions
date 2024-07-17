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
    int loves = 0;
    VI likes (N + 1); rep(1, N + 1) cin >> likes[i];
    rep(1, N + 1)
    {
        if (likes[likes[i]] == i) ++loves;
    }
    cout << loves/2 << '\n';
    return 0;
}
