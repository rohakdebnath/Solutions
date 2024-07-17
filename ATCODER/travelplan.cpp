#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI A (N + 2);
    rep(1, N + 1) cin >> A[i];
    i64 totdis = 0;
    rep(1, N + 2) totdis += abs(A[i] - A[i - 1]);
    rep(1, N + 1)
    {
        i64 k = totdis;
        k = k - abs(A[i] - A[i - 1]) - abs(A[i + 1] - A[i]) + abs(A[i + 1] - A[i - 1]);
        cout << k << '\n';
    }
    return 0;
}
