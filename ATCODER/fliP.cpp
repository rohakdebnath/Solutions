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
    int N, M, K; cin >> N >> M >> K;
    bool found = false;
    rep(r, 0, N + 1)
    {
        rep(c, 0, M + 1)
        {
            if (c*N + r*M - 2*r*c == K)
            {
                found = true;
                break;
            }
        }
    }
    cout << (found ? "Yes\n" : "No\n");
    return 0;
}
