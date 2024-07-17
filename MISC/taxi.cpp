#include <algorithm>
#include <iostream>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a >= c) cout << a << '\n';
    else{
        int gap = c - a;
        int count = gap / (b + d);
        gap -= count*(b + d);
        int ex = min(gap, b);
        cout << a + count*b + ex << '\n';
    }
    return 0;
}
