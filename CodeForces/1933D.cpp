#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 a, b, l; cin >> a >> b >> l;
    set<i64> K;
    i64 ax = 1;
    for (i64 x = 0; l % ax == 0; ++x){
        i64 by = 1;
        for (i64 y = 0; l % by == 0; ++y){
            if (l % (ax*by) == 0){
                K.insert(l / (ax*by));
            }
            by *= b;
        }
        ax *= a;
    }
    cout << K.size() << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
