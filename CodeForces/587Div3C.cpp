#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

struct Rect
{
    i64 x1;
    i64 y1;
    i64 x2;
    i64 y2;
    i64 area()
    {
        return (y2 - y1)*(x2 - x1);
    }
};

i64 intersection2(Rect a, Rect b)
{
    i64 xOverlap {max(0LL, min(a.x2, b.x2) - max(a.x1, b.x1))};
    i64 yOverlap {max(0LL, min(a.y2, b.y2) - max(a.y1, b.y1))};

    return xOverlap*yOverlap;
}

i64 intersection3(Rect a, Rect b, Rect c)
{
    i64 xOverlap {max(0LL, min(a.x2, min(b.x2, c.x2)) - max(a.x1, max(b.x1, c.x1)))};
    i64 yOverlap {max(0LL, min(a.y2, min(b.y2, c.y2)) - max(a.y1, max(b.y1, c.y1)))};

    return xOverlap*yOverlap;
}

int main()
{
    Unsync
    Rect w, b1, b2;

    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

    // cout << w.area() << ' ' << intersection2(w, b1) << ' ' << intersection2(w, b2) << ' ' << intersection2(b1, b2) << '\n';
    long long nonOverlapFor_w = w.area() - intersection2(w, b1) - intersection2(w, b2) + intersection3(w, b1, b2);

    if (nonOverlapFor_w > 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
