#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    if (2*N > M)
    {
        cout << min(N, M/2) << '\n';
    }
    else
    {
        i64 x = (M - 2*N)/4;
        cout << N + x << '\n';
    }
    return 0;
}
