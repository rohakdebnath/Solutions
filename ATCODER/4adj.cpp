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
    int F = 0, O = 0, E = 0;
    rep(0, N)
    {
        int a; cin >> a;
        if (a % 2) ++O;
        else
        {
            if (a % 4 == 0) ++F;
            else ++E;
        }
    }
    if (E == 0)
    {
        if (F >= O - 1) cout << "Yes\n";
        else cout << "No\n";
    }
    else
    {
        if (F >= O) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
