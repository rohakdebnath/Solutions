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
    rep(i, 1, N){
        i64 ini = A[i];
        A[i] = ((A[i - 1] - 1)/A[i] + 1) * A[i];
        if (A[i] == A[i - 1]) A[i] += ini;
    }
    cout << A[N - 1] << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
