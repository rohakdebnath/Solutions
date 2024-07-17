#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N; cin >> N;
    string s; cin >> s;
    vector<i64> f0 (N + 1), f1 (N + 1);

    i64 ans = N * (N + 1) / 2;
    map<i64, i64> M;
    M[0] = 1;
    rep(i, 0, N){
        i64 f = (s[i] == '1');
        f1[i + 1] = f1[i] + f;
        f0[i + 1] = f0[i] + !f;
        ans += M[f1[i + 1] - f0[i + 1]];
        ++M[f1[i + 1] - f0[i + 1]];
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
