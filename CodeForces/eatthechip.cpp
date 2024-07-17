#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int h, w, xa, ya, xb, yb; cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb){
        cout << "DRAW\n";
        return;
    }
    int dist = xb - xa;
    if (dist & 1){
        int spanalice = dist/2 + 1;
        int leftspanalice = max(ya - spanalice, 1), rightspanalice = min(ya + spanalice, w);
        int spanbob = dist/2;
        int leftspanbob = max(yb - spanbob, 1), rightspanbob = min(yb + spanbob, w);
        if (leftspanbob < leftspanalice or rightspanbob > rightspanalice){
            cout << "DRAW\n";
        } else {
            cout << "ALICE\n";
        }
    } else {
        int spanalice = dist/2;
        int leftspanalice = max(ya - spanalice, 1), rightspanalice = min(ya + spanalice, w);
        int spanbob = dist/2;
        int leftspanbob = max(yb - spanbob, 1), rightspanbob = min(yb + spanbob, w);
        if (leftspanalice < leftspanbob or rightspanalice > rightspanbob){
            cout << "DRAW\n";
        } else {
            cout << "BOB\n";
        }
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
