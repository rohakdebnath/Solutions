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
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    map<tuple<i64, i64, i64>, i64> M;
    i64 ans = 0;
    rep(i, 2, N){
        tuple<i64, i64, i64> t1 = make_tuple(0, A[i - 1], A[i]);
        tuple<i64, i64, i64> t2 = make_tuple(A[i - 2], 0, A[i]);
        tuple<i64, i64, i64> t3 = make_tuple(A[i - 2], A[i - 1], 0);
        tuple<i64, i64, i64> t4 = make_tuple(A[i - 2], A[i - 1], A[i]);
        ans = (ans + M[t1] + M[t2] + M[t3] - 3 * M[t4]);
        ++M[t1];
        ++M[t2];
        ++M[t3];
        ++M[t4];
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
