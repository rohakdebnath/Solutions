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
    if (N == 1 or M == 1)
    {
        if (N == M) cout << "1\n";
        else cout << max(N, M) - 2 << '\n';
    }
    else
    {
        cout << (N - 2)*(M - 2) << '\n';
    }
    return 0;
}
