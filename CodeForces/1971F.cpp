#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 within(i64 r){
    i64 ans = 1 + 4*r;
    rep(i, 1, r + 1){
        ans += 4 * i64(sqrt(r*r - i*i));
    }
    return ans;
}

i64 r2(i64 R) {
    i64 count = 0;
    i64 R2 = R * R;
    for (i64 x = -R; x <= R; ++x) {
        i64 y2 = R2 - x * x;
        i64 y = static_cast<i64>(std::sqrt(y2));
        if (y * y == y2) {
            ++count;
            if (y != 0) {
                ++count;
            }
        }
    }
    return count;
}


void solve()
{
    i64 r; cin >> r;
    cout << within(r + 1) - r2(r + 1) - within(r) + r2(r) << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
