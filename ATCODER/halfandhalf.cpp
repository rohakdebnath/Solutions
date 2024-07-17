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
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int yen = 0;
    if (A + B < 2*C)
    {
        yen += min(X, Y)*A + min(X, Y)*B;
    }
    else yen += 2*min(X, Y)*C;
    int t = X;
    X -= min(X, Y);
    Y -= min(t, Y);
    int extra = (X > Y ? A*X : B*Y); 
    yen += min((X + Y)*2*C, extra);

    cout << yen << '\n';
    return 0;
}
