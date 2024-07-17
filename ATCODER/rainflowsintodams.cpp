#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<i64> ans (N);
    int flip = 0;
    ans[0] = accumulate(all(A), 0LL, [&] (i64 s, i64 i) {
        flip = flip ^ 1;
        return s + (flip ? i : -i);
    });
    rep(i, 1, N){
        ans[i] = 2*A[i - 1] - ans[i - 1];
    }

    rep(i, 0, N) cout << ans[i] << " \n"[i == N - 1];
    return 0;
}
