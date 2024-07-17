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
    i64 A, B, C, D; cin >> A >> B >> C >> D;
    i64 divC = B/C - (A - 1)/C;
    i64 divD = B/D - (A - 1)/D;
    i64 lcmcd = C*D/gcd(C, D);
    i64 divCD = B/lcmcd - (A - 1)/lcmcd;

    cout << B - A + 1 - divC - divD + divCD << '\n';
    return 0;
}
