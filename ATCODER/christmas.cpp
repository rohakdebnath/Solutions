#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 NMX = 51;
i64 A[NMX], P[NMX];

i64 dfs(i64 N, i64 X){
    if (N == 0) return (X <= 0 ? 0 : 1);
    else if (X == 1) return 0;
    else if (X <= 1 + A[N - 1]) return dfs(N - 1, X - 1);
    else if (X == 2 + A[N - 1]) return P[N - 1] + 1;
    else if (X <= 2 + 2 * A[N - 1]) return P[N - 1] + 1 + dfs(N - 1, X - 2 - A[N - 1]);
    else return 2 * P[N - 1] + 1;
}

int main()
{
    UNSYNC
    A[0] = 1, P[0] = 1;
    rep(i, 1, NMX){
        A[i] = 2 * A[i - 1] + 3;
        P[i] = 2 * P[i - 1] + 1;
    }
    i64 N, X; cin >> N >> X;
    cout << dfs(N, X) << '\n';
    return 0;
}
