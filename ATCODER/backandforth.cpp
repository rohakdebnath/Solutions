#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx, dy = ty - sy;
    cout << string(dy,'U') << string(dx,'R');
    cout << string(dy,'D') << string(dx,'L');
    cout << 'L' << string(dy+1,'U') << string(dx+1,'R') << 'D';
    cout << 'R' << string(dy+1,'D') << string(dx+1,'L') << 'U';
    cout << '\n';
    return 0;
}
