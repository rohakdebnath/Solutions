#include <bits/stdc++.h>

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
    int n, m, c; cin >> n >> m >> c;
    int vgap = n - 7;
    int hgap = m - 7;
    //gotta count the no. of white blocks in (vgap + 1)x(hgap + 1) board.
    int ans = (vgap/2)*hgap + (vgap%2)*(hgap/2 + (c and hgap % 2));
    cout << ans << '\n';    
    return 0;
}
