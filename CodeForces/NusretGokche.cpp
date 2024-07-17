#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    VI A (N); rep(i, 0, N) cin >> A[i];

    rep(i, 1, N)
    {
        if (A[i] + M < A[i - 1]) A[i] += (A[i - 1] - A[i] - M);
    }
    per(i, N - 2, 0)
    {
        if (A[i] + M < A[i + 1]) A[i] += (A[i + 1] - A[i] - M);
    }
    for(i64 i: A) cout << i << ' ';
    cout << '\n';
    return 0;
}
