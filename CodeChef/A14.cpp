#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
i64 N;
i64 check (vector<i64>& A){
    i64 sum = 0;
    rep(i, 1, N){
        sum += abs(A[i] - A[i - 1]);
    }
    return sum;
}
void solve()
{
    i64 K; cin >> N >> K;
    i64 ans = 0;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    rep(i, 0, N){
        vector<i64> B = A;
        B[i] = 1;
        ans = max(ans, check(B));
        B[i] = K;
        ans = max(ans, check(B));
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
