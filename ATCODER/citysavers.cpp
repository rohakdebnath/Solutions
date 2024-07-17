#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI A (N + 1); rep(0, N + 1) cin >> A[i];
    VI B (N); rep(0, N) cin >> B[i];

    i64 count = 0;
    for (i64 i = 0; i < N; ++i)
    {
        count += min(A[i], B[i]);
        i64 temp = A[i + 1];
        if (A[i] < B[i]) A[i + 1] = max(0LL, A[i + 1] - B[i] + A[i]);
        count += temp - A[i + 1];
    }

    cout << count << '\n';
    return 0;
}
