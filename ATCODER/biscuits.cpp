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
    i64 N, P; cin >> N >> P;
    i64 E = 0, O = 0;
    rep(0, N)
    {
        i64 A; cin >> A;
        if (A % 2) ++O;
        else ++E;
    }
    i64 evenpicks = 1;
    rep(0, E) evenpicks *= 2;
    i64 oddpicks = (P == 0? O/2 + 1LL : (O + 1)/2);
    i64 pickfinal = min(1LL, oddpicks);
    rep(0, O - 1) pickfinal *= 2LL;

    cout << pickfinal*evenpicks << '\n';
    return 0;
}
