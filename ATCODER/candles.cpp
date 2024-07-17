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
    int N, K; cin >> N >> K;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    int ans = INT32_MAX;
    rep(i, K - 1, N){
        ans = min(ans, abs(A[i - K + 1]) + abs(A[i - K + 1] - A[i]));
        ans = min(ans, abs(A[i]) + abs(A[i - K + 1] - A[i]));
    }
    cout << ans << '\n';
    return 0;
}
