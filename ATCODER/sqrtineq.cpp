#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 a, b, c; cin >> a >> b >> c;
    if (c - a - b <= 0)
    {
        cout << "No\n";
        return 0;
    }
    cout << (4*a*b < (c - a - b)*(c - a - b) ? "Yes\n" : "No\n");
    return 0;
}
