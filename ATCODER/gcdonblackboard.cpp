#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A (N); rep(0, N) cin >> A[i];
    VI B (N), C (N);

    B[0] = A[0];
    for (int i = 1; i < N; ++i) B[i] = gcd(B[i - 1], A[i]);
    C[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; --i) C[i] = gcd(C[i + 1], A[i]);

    int ans = max(B[N - 2], C[1]);

    for (int i = 1; i < N - 1; ++i) ans = max(ans, gcd(B[i - 1], C[i + 1]));
    cout << ans << '\n';
    return 0;
}
