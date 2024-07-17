#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int max = -1;
    int mxscore = 0;

    rep(i, 1, 23){
        int x, y; cin >> x >> y;
        if (x + 20*y > mxscore){
            mxscore = x + 20*y;
            max = i;
        }
    }
    cout << max << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
