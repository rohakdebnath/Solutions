#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    VI preidx (N); iota(all(preidx), 0);
    sort(all(preidx), [&A] (int i, int j) {
        return A[i] < A[j];
    });
    VI mini (N), maxi (N);
    mini[preidx[0]] = A[1] - A[0];
    maxi[preidx[0]] = A[N - 1] - A[0];
    mini[preidx[N - 1]] = A[N - 1] - A[N - 2];
    maxi[preidx[N - 1]] = A[N - 1] - A[0];

    rep(i, 1, N - 1)
    {
        mini[preidx[i]] = min(A[i + 1] - A[i], A[i] - A[i - 1]);
        maxi[preidx[i]] = max(A[N - 1] - A[i], A[i] - A[0]);
    }
    rep(i, 0, N) cout << mini[i] << ' ' << maxi[i] << '\n';
    return 0;
}
