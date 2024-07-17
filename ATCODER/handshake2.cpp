#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
    map<pair<i64, i64>, i64> M;
    rep(i, 1, N + 1){
        i64 s = to_string(i)[0] - '0', e = i % 10;
        ++M[{s, e}];
    }
    i64 ans = 0;
    rep(i, 0, 10){
        rep(j, 0, 10) ans += M[{i, j}] * M[{j, i}];
    }
    cout << ans << '\n';
    return 0;
}
