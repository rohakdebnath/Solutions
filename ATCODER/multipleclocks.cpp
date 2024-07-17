#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<i64> sec (N); rep(i, 0, N) cin >> sec[i];
    i64 l = accumulate(all(sec), 1LL, [&] (i64 currl, i64 k)
    {
        return lcm(currl, k);
    });
    cout << l << '\n';
    return 0;
}
