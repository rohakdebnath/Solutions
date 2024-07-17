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
    i64 X, Y; cin >> X >> Y;
    i64 pow2 = 1;
    while (X*2 <= Y)
    {
        ++pow2;
        X *= 2;
    }
    cout << pow2<< '\n';
    return 0;
}
