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
    VI A (N), B (N), C (N - 1);
    rep(0, N) cin >> A[i];
    rep(0, N) cin >> B[i];
    rep(0, N - 1) cin >> C[i];

    int satis = 0;
    for (int i = 0; i < N; ++i)
    {
        satis += B[A[i] - 1];
        if (i > 0 and A[i] == A[i - 1] + 1) satis += C[A[i - 1] - 1];
    }

    cout << satis << '\n';
    return 0;
}
