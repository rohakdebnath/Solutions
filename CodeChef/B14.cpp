#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> P (N); rep(i, 0, N) cin >> P[i];

    vector<int> F (N); F[N - 1] = 1;
    per(i, N - 2, 0){
        if (A[i + 1] - A[i] <= P[i]) F[i] = F[i + 1] + 1;
        else F[i] = 1;
    }
    vector<int> B (N); B[0] = 1;
    rep(i, 1, N){
        if (A[i] - A[i - 1] <= P[i]) B[i] = B[i - 1] + 1;
        else B[i] = 1;
    }

    int ans = F[0] + B[N - 1];
    rep(i, 0, N - 1){
        ans = max(ans, B[i] + F[i + 1]);
    }
    if (F[0] != N) ans = max(ans, F[0] + F[F[0]]);
    if (B[N - 1] != N) ans = max(ans, B[N - 1] + B[N - 1 - B[N - 1]]);
    cout << (ans >= N ? "YES\n" : "NO\n");
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
