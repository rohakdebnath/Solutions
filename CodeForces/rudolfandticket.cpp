#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, M, S; cin >> N >> M >> S;
    vector<int> A (N); rep(i, 0, N) cin >> A[i]; sort(all(A), greater<int> ());
    vector<int> B (M); rep(i, 0, M) cin >> B[i]; sort(all(B));

    int ans = 0;
    int j = 0;
    rep(i, 0, N){
        while (B[j] + A[i] <= S and j < M) ++j;
        ans += j;
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
