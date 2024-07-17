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
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) A[i] -= i + 1;
    sort(all(A));
    i64 med = A[N/2];
    i64 ans = accumulate(all(A), 0LL, [&] (i64 s, i64 i) {return s + abs(i - med);});
    cout << ans << '\n';
    return 0;
}
