#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N, T; cin >> N >> T;
    VI t (N); rep(0, N) cin >> t[i];
    int count = 0;
    rep(1, N)
    {
        count += min(T, t[i] - t[i - 1]);
    }
    cout << count + T << '\n';
    return 0;
}
