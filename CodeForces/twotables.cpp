#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {} //constructor
};

void solve()
{
    int W, H; cin >> W >> H;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int w, h; cin >> w >> h;

    Point LL (x1, y1);
    Point UL (x1, y2);
    Point UR (x2, y2);
    Point LR (x2, y1);
    //we will create four possible arrangements and then store their inner points
    Point ll (w, h);
    Point ul (w, H - h);
    Point ur (W - w, H - h);
    Point lr (W - w, h);

    //note that since the initial table can be only translated, we will never face a situation where it has to be moved both vertically and horizontally.
    int movement = INT32_MAX;
    if (h + UR.y - LL.y > H and w + UR.x - LL.x > W)
    {
        cout << -1 << '\n';
        return;
    }
    if (LL.x < ll.x and LL.y < ll.y)
    {
        if (h + UR.y - LL.y <= H) movement = min(movement, ll.y - LL.y);
        if (w + UR.x - LL.x <= W) movement = min(movement, ll.x - LL.x);
    }
    else
    {
        cout << 0 << '\n';
        return;
    }
    if (UL.x < ul.x and UL.y > ul.y)
    {
        if (h + UR.y - LL.y <= H) movement = min(movement, UL.y - ul.y);
        if (w + UR.x - LL.x <= W) movement = min(movement, ul.x - UL.x);
    }
    else
    {
        cout << 0 << '\n';
        return;
    }
    if (UR.x > ur.x and UR.y > ur.y)
    {
        if (h + UR.y - LL.y <= H) movement = min(movement, UR.y - ur.y);
        if (w + UR.x - LL.x <= W) movement = min(movement, UR.x - ur.x);
    }
    else
    {
        cout << 0 << '\n';
        return;
    }
    if (LR.x > lr.x and LR.y < lr.y)
    {
        if (h + UR.y - LL.y <= H) movement = min(movement, lr.y - LR.y);
        if (w + UR.x - LL.x <= W) movement = min(movement, LR.x - lr.x);
    }
    else
    {
        cout << 0 << '\n';
        return;
    }
    cout << setprecision (10) << fixed;
    cout << movement << '\n';

}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
