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
    VI A (N); rep(0, N) cin >> A[i];
    int ans = 1;
    int odds = 1;
    rep(0, N)
    {
        ans *= 3;
        if (!(A[i] % 2)) odds *= 2;
    }
    cout << ans - odds << '\n';

    return 0;
}
