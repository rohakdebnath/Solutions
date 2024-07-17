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
    int N, M; cin >> N >> M;
    VI chance (N); chance[0] = 1;
    VI box (N, 1);
    rep(i, 0, M)
    {
        int x, y; cin >> x >> y; --x; --y;
        --box[x]; ++box[y];
        if (chance[x]) chance[y] = 1;
        if (box[x] == 0) chance[x] = 0;
    }
    cout << accumulate(all(chance), 0) << '\n';
    return 0;
}
