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
    int N, L, R; cin >> N >> L >> R;
    vector<int> A (N); iota(all(A), 1);
    reverse(A.begin() + L - 1, A.begin() + R);
    rep(i, 0, N) cout << A[i] << " \n"[i == N - 1];
    return 0;
}
