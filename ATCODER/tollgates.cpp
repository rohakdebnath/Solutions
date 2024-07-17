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
    int N, M, X; cin >> N >> M >> X;
    VI A (N);
    rep(0, M)
    {
        int t; cin >> t;
        ++A[t];
    }

    int c1 = 0;
    int c2 = 0;

    for(int i = X; i < N; ++i) if (A[i]) ++c1;
    for(int i = X; i >= 0; --i) if (A[i]) ++c2;

    cout << min(c1, c2) << '\n';
    return 0;
}
