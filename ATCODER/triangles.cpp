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
    i64 N; cin >> N;
    VI L (N); rep(i, 0, N) cin >> L[i];
    sort(all(L));
    i64 sets = 0;
    rep(i, 0, N)
    {
        rep(j, i + 1, N)
        {
            i64 p = distance(L.begin() + j, ranges::partition_point(j + all(L), [&] (i64 l)
            {
                if (l >= L[i] + L[j]) return false;
                else return true;
            }));
            sets += p - 1;
        }
    }
    cout << sets << '\n';
    return 0;
}
