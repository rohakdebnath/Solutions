#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 pick2(i64 P){
    return P * (P + 1) / 2;
}

void solve()
{
    i64 N, C; cin >> N >> C;
    i64 o = 0, e = 0;
    i64 diffp = 0, sump = 0;

    rep(i, 0, N){
        i64 X; cin >> X;
        X & 1 ? ++o : ++e;
        diffp += C - X + 1;
        sump += X/2 + 1;
    }
    cout << pick2(C + 1) - diffp - sump + pick2(o) + pick2(e) << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
