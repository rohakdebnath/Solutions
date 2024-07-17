#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI A (N), B (N);
    rep(0, N) cin >> A[i] >> B[i];
    i64 presses = 0;
    for(i64 i = N - 1; i >= 0; --i)
    {
        i64 diff = B[i] - ((presses + A[i]) % B[i] > 0 ? (presses + A[i]) % B[i] : B[i]);
        presses += diff;
    }
    cout << presses << '\n';
    return 0;
}
