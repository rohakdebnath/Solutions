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
    VI p (N + 2); rep(1, N + 1) cin >> p[i];
    int swaps = 0;
    rep(1, N + 1)
    {
        if (p[i] == i) swap(p[i], p[i + 1]), ++swaps;
    }
    cout << swaps << '\n';
    return 0;
}
