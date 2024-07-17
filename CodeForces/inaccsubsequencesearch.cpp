#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, M, K; cin >> N >> M >> K;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> B (M); rep(i, 0, M) cin >> B[i];

    map<int, int> BM;
    rep(i, 0, M) ++BM[B[i]];

    int ans = 0;
    map<int, int> T;
    int j = 0, t = 0;
    rep(i, 0, N - M + 1){
        while (t < K and j < N){
            if (BM[A[j]] > T[A[j]]) ++t;
            ++T[A[j]];
            ++j;
        }
        if (j - i <= M and t >= K) ++ans;
        if (BM[A[i]] >= T[A[i]]) --t;
        --T[A[i]];
    }   
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
